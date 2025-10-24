//与verilator无关的一些头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//使用verilater必须include
#include "Vtop.h" //仿真模型的头文件，由top.v生成，如果顶层文件名更改则也需要更改
#include <verilated.h>

#define CONFIG_FST_WAVE_TRACE 1

// contextp用来保存仿真的时间
VerilatedContext *contextp = new VerilatedContext;

// 构建一个名为top的仿真模型
Vtop *top = new Vtop{contextp};

//如果生成FST格式的wave
#if CONFIG_FST_WAVE_TRACE
#include "verilated_fst_c.h"            //波形文件所需的头文件
VerilatedFstC *tfp = new VerilatedFstC; // 创建一个波形文件指针
#endif

//仿真的过程
int main(int argc, char **argv)
{
    Verilated::mkdir("build/logs"); // 创建一个日志文件夹

    // 传递参数给verilator
    contextp->commandArgs(argc, argv);

//如果生成FST格式的wave
#if CONFIG_FST_WAVE_TRACE
    contextp->traceEverOn(true);          // 启用跟踪
    top->trace(tfp, 99);                  // 采样深度为99
    tfp->open("build/logs/cpu_wave.fst"); // 打开波形文件，文件地址和文件名可以自定义
#endif

    /***************对top端口的初始化*******************/
    top->clk = 0;
    top->rst = 0;

    int cnt=0;
    /**************verilator的仿真循环*****************/
    while (!contextp->gotFinish())  // ctrl+c 可以停止仿真
    {
        /************设置vtop仿真的输入信号************/
    if(++cnt > 100) break;
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->clk = !top->clk; // 随着仿真时间倒转clk，产生时钟周期
    top->eval(); //更新电路状态
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);   //按需打印想要的

    contextp->timeInc(1); //推动仿真时间

#if CONFIG_FST_WAVE_TRACE
        tfp->dump(contextp->time()); // 按照时间采样
#endif
    }

/*****************仿真结束，一些善后工作***************/
#if CONFIG_FST_WAVE_TRACE
    tfp->close(); // 关闭波形文件
#endif

    // 清理top仿真模型，并销毁相关指针，并将指针变为空指针
    top->final();
    delete top;
    top = nullptr;
    delete contextp;
    contextp = nullptr;

    return 0;
}

