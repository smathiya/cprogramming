#include <stdio.h>

#define FALSE	0
#define TRUE	1

/* ------------------------ Structures to describe computing device data  --------------------------------- */

typedef struct
{
	float approx_diagonal;
	float approx_weight;
	float approx_screen_size;
		
} DevicePhysicalInfo;

typedef struct
{
	const char *p_str_brand;
	char str_model_name[16];
	int model_year;
		
} DeviceModelInfo;

typedef struct
{
	 char serial[12];
	 
} DeviceSerialHeader;

typedef struct
{
	const char *p_str_device_type;
	DevicePhysicalInfo physical_info;
	const DeviceModelInfo *p_model;
	const DeviceSerialHeader *p_hdr_serial_numbers;
	int serial_hdr_min_index;
	int serial_hdr_max_index;	
	const void *p_att_hdr;	// Header to the data that is specific to a device type 
	
} DeviceDataDescriptor;

/* --------------------------------------------------------------------------- */

/* ------------------------ Device type specific structures to store their attributes  --------------------------------- */
typedef struct
{
	char str_box_form[4];
	int num_drives;
	
} DesktopAttributes;

typedef struct
{
	short has_optical_drive;
	short has_touch_screen;
	
} LaptopAttributes;

typedef struct
{
	short battery_hours;	
	char usb_type;			// B or C
	
} MobileAttributes;

typedef struct
{
	short supports_external_sd;
	short has_video_out;
	
} TabletAttributes;

/* ------------------------ Data Hive BEGIN --------------------------------- */

const DeviceSerialHeader g_device_serials[] = 
	{
		"G-84-986-80",
		"Y-26-896-72",
		"H-13-149-23",
		"R-65-913-82",
		"S-82-183-46",
		"E-60-498-23",
		"M-38-520-26",
		"F-20-144-87",
		"W-22-301-90",
		"E-14-163-01",
		"E-05-152-35",
		"W-69-802-06",
		"Z-57-677-07",
		"W-20-788-22",
		"D-10-526-82",
		"T-06-609-12",
		"B-62-300-42",
		"S-10-037-61",
		"N-61-847-78",
		"T-74-294-57",
		"R-66-040-28",
		"D-29-213-85",
		"W-05-277-81",
		"Q-64-451-53",
		"H-67-592-87",
		"Z-39-114-68",
		"W-14-011-05",
		"K-47-596-09",
		"Q-96-533-54",
		"E-95-852-81",
		"Z-10-713-10",
		"M-47-900-13",
		"T-67-854-24",
		"B-66-444-08",
		"U-23-438-63",
		"N-70-482-57",
		"G-35-030-95",
		"K-00-308-03",
		"Q-35-826-19",
		"T-81-313-23",
		"J-11-059-16",
		"O-28-376-54",
		"N-75-066-65",
		"C-37-803-61",
		"Z-40-808-65",
		"U-00-213-04",
		"V-00-826-27",
		"F-48-739-56",
		"E-47-705-09",
		"J-43-090-65"
	};

const char g_device_types[][8] = { "desktop", "laptop", "mobile", "tablet" };

const char g_brands[][8] = { "Dell", "HP", "Lenovo", "Acer", "LG", "Samsung", "Apple" };

const DeviceModelInfo g_device_models[] = 
	{
		{ g_brands[0], "Inspiron", 2014 },
		{ g_brands[2], "Ideacenter", 2012 },
		{ g_brands[3], "Aspire", 2015 },
		{ g_brands[1], "Pavilion", 2016 },
		{ g_brands[6], "iPhone 11", 2019 },
		{ g_brands[4], "Q60", 2018 },
		{ g_brands[2], "Yoga Tab", 2018 },
		{ g_brands[5], "Galaxy Tab", 2017 }
	};
	
const DesktopAttributes g_atts_desktop[] = 
	{
		{"VERT", 2},
		{"FLAT", 1},
		{"VERT", 3},
		{"FLAT", 2}
	};
	
const LaptopAttributes g_atts_laptop[] = 
	{
		{FALSE, FALSE},
		{FALSE, TRUE},
		{TRUE, FALSE},
		{TRUE, FALSE}
	};

const MobileAttributes g_atts_mobile[] = 
	{
		{36, 'B'},
		{44, 'B'},
		{50, 'B'},
		{38, 'C'},
		{56, 'C'}
	};

const TabletAttributes g_atts_tablet[] = 
	{
		{FALSE, FALSE},
		{FALSE, TRUE},
		{TRUE, FALSE},
		{TRUE, FALSE}
	};

// Data Descriptors

const DeviceDataDescriptor g_desktop_descriptor = 
	{
		g_device_types[0],
		{36, 5000, 21},
		&g_device_models[0],
		&g_device_serials[0],
		0,
		9,
		&g_atts_desktop
	};
	
const DeviceDataDescriptor g_laptop_descriptor = 
	{
		g_device_types[1],
		{20, 2000, 16},
		&g_device_models[2],
		&g_device_serials[0],
		10,
		17,
		&g_atts_laptop
	};
	
const DeviceDataDescriptor g_mobile_descriptor = 
	{
		g_device_types[2],
		{8, 300, 6},
		&g_device_models[4],
		&g_device_serials[0],
		18,
		37,
		&g_atts_mobile
	};

const DeviceDataDescriptor g_tablet_descriptor = 
	{
		g_device_types[3],
		{12, 600, 10},
		&g_device_models[6],
		&g_device_serials[0],
		38,
		49,
		&g_atts_tablet
	};

/* ------------------------ Data Hive END --------------------------------- */

typedef enum
{
	DT_DESKTOP,
	DT_LAPTOP,
	DT_MOBILE,
	DT_TABLET,

} DeviceTypeIndex;	// Must match g_device_types

typedef struct
{
	DeviceTypeIndex type;
	const DeviceDataDescriptor *p_desc;
	short serial_index;		// from DeviceDataDescriptor::serial_hdr_min_index to serial_hdr_max_index
	int model_index : 1;	// 0 or 1
	int att_index	: 3;

} DeviceInstance;

// Initializes Device instance with data descriptor
void InitializeDeviceWithDataDesc(DeviceInstance *device, const DeviceTypeIndex type)
{
	if (device == NULL) return;

	switch (type)
	{
	case DT_DESKTOP:
		device->p_desc = &g_desktop_descriptor;
		break;
		
	case DT_LAPTOP:
		device->p_desc = &g_laptop_descriptor;
		break;

	case DT_MOBILE:
		device->p_desc = &g_mobile_descriptor;
		break;

	case DT_TABLET:
		device->p_desc = &g_tablet_descriptor;
		break;
	}
}

// Function to set the device instance values
void SetDeviceInstanceValues(DeviceInstance *device, DeviceTypeIndex type, short serial_index, int model_index, int att_index)
{
	InitializeDeviceWithDataDesc(device, type);

	/* TODO : Complete rest of this function */
	/* NOTE : Validate the indices passed to this function whether they are in the range as per device */


}


// Print the attributes of a given desktop instance
void PrintDesktopDeviceAttributes(const DesktopAttributes *att)
{
	/* TODO : Complete this function */
}

// Print the attributes of a given laptop instance
void PrintLaptopDeviceAttributes(const LaptopAttributes *att)
{
	/* TODO : Complete this function */
}

// Print the attributes of a given mobile instance
void PrintMobileDeviceAttributes(const MobileAttributes *att)
{
	/* TODO : Complete this function */
}

// Print the attributes of a given tablet instance
void PrintTabletDeviceAttributes(const TabletAttributes *att)
{
	/* TODO : Complete this function */
}

// Print the complete details about a given device instance
void PrintDeviceDetails(const DeviceInstance *device)
{
	/* TODO: Complete this function */

	// Hints:
	// Print the device type
	// Print rest of the device details using its descriptor
	// Call the appropriate print function above for the attributes
}

static DeviceInstance s_desktop_obj;
static DeviceInstance s_laptop_obj;
static DeviceInstance s_mobile_obj;
static DeviceInstance s_tablet_obj;

int main()
{
	SetDeviceInstanceValues(&s_desktop_obj, DT_DESKTOP, 3, 0, 1);
	SetDeviceInstanceValues(&s_laptop_obj, DT_LAPTOP, 12, 1, 3);
	SetDeviceInstanceValues(&s_mobile_obj, DT_MOBILE, 25, 1, 0);
	SetDeviceInstanceValues(&s_tablet_obj, DT_TABLET, 47, 0, 2);
	
	PrintDeviceDetails(&s_desktop_obj);
	PrintDeviceDetails(&s_laptop_obj);
	PrintDeviceDetails(&s_mobile_obj);
	PrintDeviceDetails(&s_tablet_obj);
}
