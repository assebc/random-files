# pips
# pip install youtube-dl
# pip install pyinstaller

# Imports here
from youtube_dl import YoutubeDL

# Get extension
audio_downloader = YoutubeDL({"format":"bestaudio"})

while True:
	
	try:

		# Print header
		print(" Youtube MP3 Converter ".center(40, '=') )

		# Get link
		URL = input("Enter youtube url : ")

		# Download music
		audio_downloader.extract_info(URL)

	# If an error occurs
	except Exception:

		print(" Couldn't download the audio ".center(40, '='))

	# Before closing
	finally:

		print(" Success, Thank you for using me ".center(40, '=') )
		break

