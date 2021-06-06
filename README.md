# QToggleButton

## Summary

This is a toggle button class inherit QCheckBox.

## Demo

QToggleButton has the same checked states as QCheckBox.<br>
You can use tri state.

1. Qt::UnChecked<br>
   <img src="pictures\off.png" alt="off"  />
3. Qt::PartiallyChecked<br>
   <img src="pictures\partially.png" alt="partially"  />
4. Qt::Checked<br>
   <img src="pictures\on.png" alt="on"  />

## Features

You can move the slider away from text by using "setSliderLayout()".<br>
<img src="pictures\far.png" alt="far"  />

You can set icon same as QCheckBox.<br>
The icon is set the left of text.

You can change slider style by using stylesheet.<br>Please refer to "example/SampleWindow.cpp".<br>![style](pictures\style.png)

## Installation

If you use Visual Studio, run "example.vcxproj".<br>
Please change the project settings according to your environment.<br>
As refer, I use "Visual Studio 2015" and "Qt 5.6.3".

## Author

- Yoshito Kumakura
- kumakura.yoshito@gmail.com

## License

QToggleButton is under [Unlicense](https://github.com/Kuma4410/QToggleButton/blob/main/LICENSE).

