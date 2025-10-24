#!/bin/sh

mkdir -p build/logs/ >> /dev/null
verilator -Wall top.v main.cpp --cc --trace-fst --exe --Wno-UNUSED --Wno-UNOPTFLAT --build
./obj_dir/Vtop >> /dev/null
gtkwave ./build/logs/cpu_wave.fst