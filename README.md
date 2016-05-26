# ASCII Watchface

When challenged to create an analogue ASCII clock for display in the terminal, I couldn't pass up the opportunity to completely ignore the "terminal" part of the challenge and implement it on my wristwatch instead.

Here's how it looks:

![Watchface IRL](https://github.com/ThinTim/ascii-watchface/raw/master/pebble_time.jpg)

## The Original Challenge

In this challenge you must draw an analogue clock face.

- The time is supplied on stdin in the format hh:mm, followed by a single newline. Both hh and mm are padded with a leading 0 (zero) if they are less than 10.
- The analogue clock face representing that time, subject to the following rules, should be written on stdout.
- Each hour mark should be drawn with 'o' (Lower-case O).
- The hour mark representing the hour given in the input should be drawn with an 'h'.
- The hour mark representing the minute given in the input should be drawn with an 'm'.
- If the hour and the minute both fall on the same mark, then you should draw it with an 'x'.
- You should round down the minutes past the hour to the nearest 5 for the purposes of marking it on the clock (so 23 becomes 20, 39 becomes 35).

### Examples:

```
21:35

        o
    o       o

 o             o

h               o

 o             o

    m       o
        o
```



```
04:59

        o
    m       o

 o             o

o               o

 o             h

    o       o
        o
```
