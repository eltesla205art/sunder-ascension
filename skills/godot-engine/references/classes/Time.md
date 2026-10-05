# Time

**Inherits:** Object

A singleton for working with time data.

The Time singleton allows converting time between various formats and also getting time information from the system. This class conforms with as many of the ISO 8601 standards as possible. All dates follow the Proleptic Gregorian calendar. As such, the day before `1582-10-15` is `1582-10-14`, not `1582-10-04`.

## Methods

- `get_date_dict_from_system(utc: bool = false) -> Dictionary` *const* — Returns the current date as a dictionary of keys: `year`, `month`, `day`, and `weekday`.
- `get_date_dict_from_unix_time(unix_time_val: int) -> Dictionary` *const* — Converts the given Unix timestamp to a dictionary of keys: `year`, `month`, `day`, and `weekday`.
- `get_date_string_from_system(utc: bool = false) -> String` *const* — Returns the current date as an ISO 8601 date string (YYYY-MM-DD).
- `get_date_string_from_unix_time(unix_time_val: int) -> String` *const* — Converts the given Unix timestamp to an ISO 8601 date string (YYYY-MM-DD).
- `get_datetime_dict_from_datetime_string(datetime: String, weekday: bool) -> Dictionary` *const* — Converts the given ISO 8601 date and time string (YYYY-MM-DDTHH:MM:SS) to a dictionary of keys: `year`, `month`, `day`, `weekday`, `hour`, `minute`, and `second`.
- `get_datetime_dict_from_system(utc: bool = false) -> Dictionary` *const* — Returns the current date as a dictionary of keys: `year`, `month`, `day`, `weekday`, `hour`, `minute`, `second`, and `dst` (Daylight Savings Time).
- `get_datetime_dict_from_unix_time(unix_time_val: int) -> Dictionary` *const* — Converts the given Unix timestamp to a dictionary of keys: `year`, `month`, `day`, `weekday`, `hour`, `minute`, and `second`.
- `get_datetime_string_from_datetime_dict(datetime: Dictionary, use_space: bool) -> String` *const* — Converts the given dictionary of keys to an ISO 8601 date and time string (YYYY-MM-DDTHH:MM:SS).
- `get_datetime_string_from_system(utc: bool = false, use_space: bool = false) -> String` *const* — Returns the current date and time as an ISO 8601 date and time string (YYYY-MM-DDTHH:MM:SS).
- `get_datetime_string_from_unix_time(unix_time_val: int, use_space: bool = false) -> String` *const* — Converts the given Unix timestamp to an ISO 8601 date and time string (YYYY-MM-DDTHH:MM:SS).
- `get_offset_string_from_offset_minutes(offset_minutes: int) -> String` *const* — Converts the given timezone offset in minutes to a timezone offset string.
- `get_ticks_msec() -> int` *const* — Returns the amount of time passed in milliseconds since the engine started.
- `get_ticks_usec() -> int` *const* — Returns the amount of time passed in microseconds since the engine started.
- `get_time_dict_from_system(utc: bool = false) -> Dictionary` *const* — Returns the current time as a dictionary of keys: `hour`, `minute`, and `second`.
- `get_time_dict_from_unix_time(unix_time_val: int) -> Dictionary` *const* — Converts the given time to a dictionary of keys: `hour`, `minute`, and `second`.
- `get_time_string_from_system(utc: bool = false) -> String` *const* — Returns the current time as an ISO 8601 time string (HH:MM:SS).
- `get_time_string_from_unix_time(unix_time_val: int) -> String` *const* — Converts the given Unix timestamp to an ISO 8601 time string (HH:MM:SS).
- `get_time_zone_from_system() -> Dictionary` *const* — Returns the current time zone as a dictionary of keys: `bias` and `name`. - `bias` is the offset from UTC in minutes, since not all time zones are multiples of an hour from UTC. - `name` is the localized name of the time zone, according to the OS locale settings of the current user.
- `get_unix_time_from_datetime_dict(datetime: Dictionary) -> int` *const* — Converts a dictionary of time values to a Unix timestamp.
- `get_unix_time_from_datetime_string(datetime: String) -> int` *const* — Converts the given ISO 8601 date and/or time string to a Unix timestamp.
- `get_unix_time_from_system() -> float` *const* — Returns the current Unix timestamp in seconds based on the system time in UTC.

## Enum Month

- `MONTH_JANUARY = 1` — The month of January, represented numerically as `01`.
- `MONTH_FEBRUARY = 2` — The month of February, represented numerically as `02`.
- `MONTH_MARCH = 3` — The month of March, represented numerically as `03`.
- `MONTH_APRIL = 4` — The month of April, represented numerically as `04`.
- `MONTH_MAY = 5` — The month of May, represented numerically as `05`.
- `MONTH_JUNE = 6` — The month of June, represented numerically as `06`.
- `MONTH_JULY = 7` — The month of July, represented numerically as `07`.
- `MONTH_AUGUST = 8` — The month of August, represented numerically as `08`.
- `MONTH_SEPTEMBER = 9` — The month of September, represented numerically as `09`.
- `MONTH_OCTOBER = 10` — The month of October, represented numerically as `10`.
- `MONTH_NOVEMBER = 11` — The month of November, represented numerically as `11`.
- `MONTH_DECEMBER = 12` — The month of December, represented numerically as `12`.

## Enum Weekday

- `WEEKDAY_SUNDAY = 0` — The day of the week Sunday, represented numerically as `0`.
- `WEEKDAY_MONDAY = 1` — The day of the week Monday, represented numerically as `1`.
- `WEEKDAY_TUESDAY = 2` — The day of the week Tuesday, represented numerically as `2`.
- `WEEKDAY_WEDNESDAY = 3` — The day of the week Wednesday, represented numerically as `3`.
- `WEEKDAY_THURSDAY = 4` — The day of the week Thursday, represented numerically as `4`.
- `WEEKDAY_FRIDAY = 5` — The day of the week Friday, represented numerically as `5`.
- `WEEKDAY_SATURDAY = 6` — The day of the week Saturday, represented numerically as `6`.
