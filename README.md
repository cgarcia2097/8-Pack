# 8-Key-Pro-Micro-Keypad
Repository for design files, source code and assembly guides regarding this keypad. Inspired by di0ib's Six Pack design, this keypad project is intended for me on learning how to use PCB software. Mishaps, snafus and foobars expected and incoming.

# Some info
- Key Unit Size: 19 mm 

If using swillkb's plate editor don't forget to set the unit size to 19 mm. Otherwise, the centers of each switch are 19 mm 

Currently a work in progress.

# Update 09/27/2018
First batch of PCBs have arrived from Aisler. I am happy to report that the PCBs are of high quality, as well as my footprints being correct and accurate. The parts fit together like a charm. 

Unfortunately, the existing gerbers on the repo exhibit issues discussed below:

- RESET and GND are short for some reason. Verified with a continuity check for the entire batch. Must be my fault since they are short for all three. Just don't connect anything to the RST header on the Pro Micro, and it should work.

- The USB port on the Pro Micro touches switch #3 contacts, and interferes with the operation. Current workaround is to use a machine socket to hold the Pro Micro in place. See di0ib's use of sockets here: http://www.40percent.club/2017/04/six-pack-10.html

Otherwise I am happy to report that the keyboard is mostly functional and ready to rock some Arduino code. Will be posting footage on my youtube channel when time permits.
