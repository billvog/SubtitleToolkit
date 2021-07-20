<p align="center" title="SubStudio icon">
  <img height=256 src="https://raw.githubusercontent.com/billvog/kincasta-studio/main/assets/colored-icon.png"/>
</p>

# Kincasta Studio

Kincasta is a free software licensed under the GPLv3 license that helps you create subtitles with ease.

---

Kincasta is built with the Qt framework version 5.15.2 with C++. The project unfortunately cannot be upgraded to Qt6 because Multimedia and MultimediaWidgets are removed in this version and the program is based on them.

The [Qt team said](https://doc-snapshots.qt.io/qt6-dev/whatsnew60.html#removed-modules-in-qt-6-0) that they will reimplement these in a future version, until then, this project will be compiled with Qt5

_Note_: Qt team announced the release of version 6.2 (that includes the new Multimedia stuff) and according to what I read the final release will be on September.

More about that [here](https://wiki.qt.io/Qt_6.2_Release) and [here](https://www.qt.io/blog/qt-multimedia-in-qt-6).

---

The media player Kincasta has currently needs codecs to be installed (hopefully on 6.2 the multimedia backends will have codes installed in them!). I successfully tested [Pro Video Formats](https://support.apple.com/kb/DL2050) on MacOS and [K-Lite Codec Pack](https://codecguide.com/download_kl.htm) on Windows.

---

Feel free to contribute to the project by making a pull request.
