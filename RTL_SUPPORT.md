# RTL (Right-to-Left) Support for Hebrew

This fork adds RTL text rendering support for Hebrew and other right-to-left languages to the ESPHome Transit Tracker component.

## What's New

### RTL Mode Configuration
A new `rtl_mode` option has been added to the transit_tracker component that enables proper right-to-left text rendering and layout.

### Features Implemented

1. **Text Reversal**: Hebrew text strings are automatically reversed so they display correctly on LED matrices
2. **Flipped Layout**: When RTL mode is enabled, the schedule display layout is mirrored:
   - Times appear on the LEFT side
   - Route names appear on the RIGHT side
   - Headsigns/destinations appear in the middle (reversed)
   - Realtime icons are positioned correctly for RTL layout

3. **Status Message Support**: All centered status messages (loading, errors, etc.) are properly reversed when in RTL mode

## Usage

### Basic Configuration

Add `rtl_mode: true` to your transit_tracker configuration:

```yaml
transit_tracker:
  id: tracker
  base_url: "wss://tt.horner.tj/"
  rtl_mode: true  # Enable RTL mode for Hebrew
  limit: 3
  feed_code: "il-mot"
  stops:
    - stop_id: "YOUR_STOP_ID"
      routes:
        - "YOUR_ROUTE_ID"
```

### Hebrew Font Setup

You must use a font that supports Hebrew characters. For example, ChavaRegular:

```yaml
font:
  - file: "fonts/ChavaRegular.ttf"
    id: chava
    size: 10
    glyphs:
      - "אבגדהוזחטיכךלמםנןסעפףצץקרשת"  # Hebrew characters
      - "0123456789.:;!? "               # Numbers and punctuation
```

### Timezone Configuration

For Israeli transit systems, set the timezone appropriately:

```yaml
time:
  - platform: sntp
    id: sntp_time
    timezone: Asia/Jerusalem
```

### Complete Example

See `examples/matrix-portal-s3-hebrew.yaml` for a complete working configuration.

## Technical Details

### Modified Files

1. **`components/transit_tracker/__init__.py`**
   - Added `rtl_mode` configuration option
   - Added setter method registration

2. **`components/transit_tracker/string_utils.h/.cpp`**
   - Added `reverse_string()` utility function

3. **`components/transit_tracker/transit_tracker.h`**
   - Added `rtl_mode_` boolean property
   - Added `set_rtl_mode()` setter method

4. **`components/transit_tracker/transit_tracker.cpp`**
   - Modified `draw_text_centered_()` to reverse text when RTL is enabled
   - Completely rewrote `draw_trip()` to support flipped layout:
     - Dynamic positioning based on RTL mode
     - Proper clipping regions for RTL
     - Correct realtime icon positioning
     - Reversed headsign text

### How It Works

#### Text Reversal
Hebrew text is stored in memory in logical order (right-to-left), but LED matrices render pixels left-to-right. The `reverse_string()` function reverses the byte order so that when rendered left-to-right, the text appears in the correct right-to-left visual order.

#### Layout Flipping
In RTL mode:
- LTR: `[Route] [Headsign...] [Icon] [Time]`
- RTL: `[Time] [Icon] [Headsign...] [Route]`

The component dynamically calculates positions and clipping regions based on the `rtl_mode_` flag.

## Limitations

### Bidirectional Text
The current implementation assumes pure Hebrew text. Mixed Hebrew/English text may not render correctly. If you need bidirectional text support (mixed RTL/LTR), additional logic would be needed to detect and handle text direction changes.

### Character Encoding
Make sure your YAML files are saved with UTF-8 encoding to properly handle Hebrew characters.

## Testing

To test the RTL implementation:

1. Configure your transit tracker with `rtl_mode: true`
2. Use Hebrew status messages (already implemented in the code)
3. Verify that:
   - Times appear on the left
   - Route names appear on the right
   - Hebrew text reads correctly from right to left
   - Scrolling works properly for long headsigns

## Status Messages (Hebrew)

The following Hebrew status messages are built into the code:

- "מחכה לחיבור לאינטרנט" - Waiting for network connection
- "מחכה לסנכרון זמן" - Waiting for time sync
- "לא הוגדרה כתובת לשרת" - No server address configured
- "שגיאה בטעינת לוח הזמנים" - Error loading schedule
- "טוען..." - Loading...
- "אין זמני הגעה קרובים" - No upcoming arrivals
- "אין זמני יציאה קרובים" - No upcoming departures

## Contributing

If you find issues with RTL rendering or have suggestions for improvements, please open an issue or submit a pull request.

## License

This fork maintains the original MIT License from tjhorner/esphome-transit-tracker.

