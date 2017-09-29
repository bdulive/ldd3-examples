# Test with dummy_hcd & g_zero

dummy_hcd driver is a USB simulator, it can act like a UDC.
g_zero is used primarily for testing and development with drivers for usb controller hardware.
Both dummy_hcd and g_zero together act as a USB device connected to USB host.

Since dummy_hcd is not selected in Ubuntu kenrel by default, first make menuconfig and select it at:
	"> Device Drivers > USB support > USB Gadget Support > USB Peripheral Controller > Dummy HCD (DEVELOPMENT)"

Having dummy_hcd.ko & g_zero.ko, issue below command and /dev/skel0 will appear:
	modprobe dummy_hcd g_zero && insmod usb-skeleton.ko

Echo something to /dev/skel0 and read back from it:
	echo 1234567 > /dev/skel0 && cat /dev/skel0
