
# 🎥 gstreamer-fps-monitor

A simple C application that uses **GStreamer** to play a video file and overlay **real-time FPS (Frames Per Second)** on the video window. This project helps monitor video rendering performance and serves as a beginner-friendly example of building GStreamer pipelines in C.

---

## 📁 Project Structure

```
gstreamer-fps-monitor/
├── main.c              # C source file containing the pipeline
├── Makefile            # For compiling, running, and cleaning
├── sample.mp4          # Sample video file (must be added manually)
└── README.md           # Documentation and usage guide
```

---

## 🧰 Requirements

Install the following dependencies before building:

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install -y build-essential pkg-config \
libgstreamer1.0-dev gstreamer1.0-plugins-base \
gstreamer1.0-tools gstreamer1.0-libav
```

Verify GStreamer installation:

```bash
gst-launch-1.0 --version
```

---

## 🚀 Features

- Plays any video file supported by GStreamer
- Displays real-time FPS overlay
- Easy to compile and run using a Makefile
- Beginner-friendly GStreamer example in C

---

## 🧪 Pipeline Overview

The application builds this GStreamer pipeline internally:

```
filesrc → decodebin → fpsdisplaysink → autovideosink
```

- `filesrc`: Reads video from disk  
- `decodebin`: Automatically decodes input format  
- `fpsdisplaysink`: Adds FPS overlay to the video  
- `autovideosink`: Displays video in a native window

---

## ⚙️ How to Compile and Run

### Step 1: Add a Sample Video

Make sure to have a file named `sample.mp4` in the root folder (or any `.mp4` video renamed accordingly).

You can use any short test video.

### Step 2: Compile the Project

Use the provided Makefile:

```bash
make
```

This creates an executable called `gstreamer_fps_monitor`.

### Step 3: Run the Program

```bash
make run
```

Or manually:

```bash
./gstreamer_fps_monitor sample.mp4
```

### Step 4: Clean the Build

```bash
make clean
```

This deletes the binary executable.

---

## 📌 Notes

- The application supports any video format supported by GStreamer.
- FPS is displayed on the top-left of the video window.
- If the video file is missing or the format is unsupported, the program exits with an error.

---

## 💡 Sample Makefile Commands

```bash
make        # Compile the program
make run    # Run the program with sample.mp4
make clean  # Remove the compiled binary
```

---

