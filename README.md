## TWRP Device Tree for the Galaxy J5 2015 NFC (j5nlte)

### How to build
1. Get the 
[minimal-manifest-twrp](https://github.com/minimal-manifest-twrp/platform_manifest_twrp_omni/tree/twrp-8.1)
(omni twrp-8.1 branch) and follow the instructions there

2. Clone this repository to `device/samsung/j5nlte`
```
git clone https://github.com/prototype74/android_device_samsung_j5nlte.git -b android-8.1 device/samsung/j5nlte
```

3. Build the recovery image
```bash
export ALLOW_MISSING_DEPENDENCIES=true; . build/envsetup.sh; lunch omni_j5nlte-eng; mka recoveryimage
```
