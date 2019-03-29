EESchema Schematic File Version 4
LIBS:neopixel_plates-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x03_Male J1
U 1 1 5C947F82
P 4700 3900
F 0 "J1" H 4806 4178 50  0000 C CNN
F 1 "Conn_01x03_Male" H 4806 4087 50  0000 C CNN
F 2 "libkeyswitch-1_0_0:NEOPIXEL_PADS" H 4700 3900 50  0001 C CNN
F 3 "~" H 4700 3900 50  0001 C CNN
	1    4700 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5C9480B5
P 5450 3900
F 0 "J3" H 5556 4178 50  0000 C CNN
F 1 "Conn_01x03_Male" H 5556 4087 50  0000 C CNN
F 2 "libkeyswitch-1_0_0:NEOPIXEL_PADS" H 5450 3900 50  0001 C CNN
F 3 "~" H 5450 3900 50  0001 C CNN
	1    5450 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J2
U 1 1 5C948167
P 4700 4400
F 0 "J2" H 4806 4678 50  0000 C CNN
F 1 "Conn_01x03_Male" H 4806 4587 50  0000 C CNN
F 2 "libkeyswitch-1_0_0:NEOPIXEL_PADS" H 4700 4400 50  0001 C CNN
F 3 "~" H 4700 4400 50  0001 C CNN
	1    4700 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5C948174
P 5500 4400
F 0 "J4" H 5606 4678 50  0000 C CNN
F 1 "Conn_01x03_Male" H 5606 4587 50  0000 C CNN
F 2 "libkeyswitch-1_0_0:NEOPIXEL_PADS" H 5500 4400 50  0001 C CNN
F 3 "~" H 5500 4400 50  0001 C CNN
	1    5500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 4500 6000 4500
Wire Wire Line
	6000 4500 6000 4000
Wire Wire Line
	6000 4000 5650 4000
Wire Wire Line
	5700 4400 6050 4400
Wire Wire Line
	6050 4400 6050 3900
Wire Wire Line
	6050 3900 5650 3900
Wire Wire Line
	5700 4300 6100 4300
Wire Wire Line
	6100 4300 6100 3800
Wire Wire Line
	6100 3800 5650 3800
Text GLabel 4950 4300 2    50   Input ~ 0
GND
Text GLabel 4950 3800 2    50   Input ~ 0
GND
Text GLabel 4950 4500 2    50   Input ~ 0
VCC
Text GLabel 4950 4000 2    50   Input ~ 0
VCC
Wire Wire Line
	4900 3800 4950 3800
Wire Wire Line
	4900 4000 4950 4000
Wire Wire Line
	4900 4300 4950 4300
Wire Wire Line
	4900 4500 4950 4500
Text GLabel 6150 3800 2    50   Input ~ 0
GND
Text GLabel 6150 4000 2    50   Input ~ 0
VCC
Wire Wire Line
	6150 3800 6100 3800
Connection ~ 6100 3800
Wire Wire Line
	6150 4000 6000 4000
Connection ~ 6000 4000
$EndSCHEMATC
