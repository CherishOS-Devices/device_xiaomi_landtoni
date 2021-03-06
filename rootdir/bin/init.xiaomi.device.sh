#!/vendor/bin/sh

if grep S88537 /proc/cmdline ; then
	# land
	setprop ro.vendor.xiaomi.device land

	# Camera
	setprop camera.lowpower.record.enable 0
	setprop persist.camera.gyro.android 0
	setprop persist.camera.gyro.disable 1
	setprop persist.camera.is_type 1
	setprop persist.ts.rtmakeup true
	setprop media.camera.ts.monotonic 1

	# Fingerprint
	if grep -E "S88537AC1|S88537EC1" /proc/cmdline ; then
		setprop ro.vendor.fingerprint.supported 0
	else
		setprop ro.vendor.fingerprint.supported 2
	fi
elif grep S88536 /proc/cmdline ; then
	# santoni
	setprop ro.vendor.xiaomi.device santoni

	# Fingerprint
	setprop ro.vendor.fingerprint.supported 2
	setprop vendor.fingerprint.goodix.disable_notify_cancel_hack 1
fi

exit 0
