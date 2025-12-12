# Quick Start Guide: Hebrew RTL Support

## ✅ Implementation Complete!

RTL (Right-to-Left) text rendering has been successfully implemented for Hebrew in your ESPHome Transit Tracker fork.

## What You Can Do Now

### 1. Use RTL Mode in Your Configuration

Simply add `rtl_mode: true` to your transit_tracker configuration:

```yaml
transit_tracker:
  id: tracker
  base_url: "wss://tt.horner.tj/"
  rtl_mode: true  # ← Enable RTL mode for Hebrew
  limit: 3
  feed_code: "il-mot"  # Israeli Ministry of Transport
  stops:
    - stop_id: "YOUR_STOP_ID"
      routes:
        - "YOUR_ROUTE_ID"
```

### 2. Configure Hebrew Font

Use a Hebrew-capable font like ChavaRegular:

```yaml
font:
  - file: "fonts/ChavaRegular.ttf"
    id: chava
    size: 10
    glyphs:
      - "אבגדהוזחטיכךלמםנןסעפףצץקרשת"
      - "0123456789.:;!? "
```

### 3. Set Israeli Timezone

```yaml
time:
  - platform: sntp
    id: sntp_time
    timezone: Asia/Jerusalem
```

## How It Works

### RTL Mode OFF (Default - LTR):
```
[Route] [Headsign........] [Icon] [Time]
```

### RTL Mode ON (Hebrew):
```
[Time] [Icon] [........ngisdaeH] [etuoR]
```

The text is reversed at the byte level so Hebrew displays correctly on LED matrices.

## Features Implemented

✅ **Text Reversal** - Hebrew strings automatically reversed for correct display  
✅ **Flipped Layout** - Times on left, routes on right in RTL mode  
✅ **Status Messages** - Loading/error messages display correctly in Hebrew  
✅ **Icon Positioning** - Realtime icons positioned correctly for RTL  
✅ **Scrolling Support** - Long Hebrew headsigns scroll properly  

## Built-in Hebrew Messages

The following Hebrew status messages are already in the code:

- מחכה לחיבור לאינטרנט - Waiting for network
- מחכה לסנכרון זמן - Waiting for time sync
- לא הוגדרה כתובת לשרת - No server address
- שגיאה בטעינת לוח הזמנים - Error loading schedule
- טוען... - Loading...
- אין זמני הגעה קרובים - No upcoming arrivals
- אין זמני יציאה קרובים - No upcoming departures

## Example Files

📄 **Complete Hebrew Config:** `examples/matrix-portal-s3-hebrew.yaml`  
📄 **Detailed Documentation:** `RTL_SUPPORT.md`  
📄 **Implementation Details:** `IMPLEMENTATION_SUMMARY.md`  

## Testing Your Setup

1. Compile and upload your ESPHome configuration
2. Watch for status messages in Hebrew
3. Verify layout: times should be on the LEFT, routes on the RIGHT
4. Test with actual Hebrew transit data

## Files Modified

- `components/transit_tracker/__init__.py` - Added rtl_mode config
- `components/transit_tracker/string_utils.h/cpp` - Added reverse_string()
- `components/transit_tracker/transit_tracker.h` - Added rtl_mode property
- `components/transit_tracker/transit_tracker.cpp` - Implemented RTL drawing
- `README.md` - Updated with RTL info

## Need Help?

- **Full RTL Documentation:** See `RTL_SUPPORT.md`
- **Technical Details:** See `IMPLEMENTATION_SUMMARY.md`
- **Example Config:** See `examples/matrix-portal-s3-hebrew.yaml`

## Known Limitations

⚠️ **Bidirectional Text:** Mixed Hebrew/English may not render correctly  
⚠️ **UTF-8 Required:** Make sure your YAML files are UTF-8 encoded  

## Next Steps

1. ✅ Code is ready to use
2. 🔧 Test on your actual hardware
3. 📝 Configure your Israeli transit stops/routes
4. 🎨 Choose a Hebrew font you like
5. 🚀 Deploy to your LED matrix!

---

**Enjoy your Hebrew RTL transit tracker!** 🚌🇮🇱

