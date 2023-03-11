from pytube import YouTube
from moviepy.editor import *

# Enter the YouTube video URL
url = input("Enter the YouTube video URL: ")

# Download the video
video = YouTube(url).streams.filter(only_audio=True).first().download()

# Convert the video to an .mp3 file
mp3_file = video.split(".")[0] + ".mp3"
videoclip = AudioFileClip(video)
videoclip.write_audiofile(mp3_file)
videoclip.close()

print("The music has been downloaded and saved as", mp3_file)