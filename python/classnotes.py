import json
from datetime import datetime

r = sr.Recognizer()
run = True
data = {}
with open("notepad.json", "r") as f:
	data =json.load(f)

while run:
	with sr.Microphone() as source:
		print("Working")
		audio_text = r.listen(source)
		print("Done")
		try:
			text = r.recognize_google(audio_text)
			print(json.dumps(data, indent = 4))
			now = datetime.now()
			timestamp = datetime.timestamp(now)
			data["notes"].append({
				str(timestamp) : text
				})
			with open("notepad.json", "w") as outfile:
				outfile.write(json.dumps(data, indent = 4))
		except KeyboardInterrupt:
			print("Stopping")
		except:
			print("Error")
			run = False
