#!/bin/sh

# sox -n -r 44100 -b 16 alarm.wav \
# synth 0.15 sin 5700 delay 0.09 \
# repeat 500

sox -n -r 44100 -b 16 alarm.wav synth 0.15 \
sin 5700 vol 1 delay 0.09 sin 440 vol 0.05 \
repeat 100


# ffmpeg -i alarm.wav -ar 44100 -ac 1 -sample_fmt s16 alarm_fixed.wav


# ffmpeg -i ./alarm.wav -ar 44100 -sample_fmt s16 ./alarm.mp3