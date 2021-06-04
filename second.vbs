Set Sapi = Wscript.CreateObject("SAPI.SpVoice")
set wshshell = wscript.CreateObject("wscript.shell")

dim Input
dim Input1

Sapi.speak "Would you like to enjoy other services while you wait?"
Input=inputbox ("Would you like to enjoy other services while you wait?"& vbCrLf &"Yes "& vbCrLf &"No")


if Input = "yes" OR Input = "Yes" then
Sapi.speak "Thank you, would you like to listen to music or watch some videos or verify your bill? while we process your order"
Input1 = inputbox("About VARS"& vbCrLf & "Music"& vbCrLf &"Videos"& vbCrLf &"Calculator"& vbCrLf &"Google the web ?")

if Input1 = "videos" OR Input1 = "Videos" OR Input1 = "video" then
Sapi.speak "Opening youtube"
wshshell.run "www.youtube.com"

else
if Input1 = "Music" OR Input1 = "music" then
Sapi.speak "Opening Spotify"
wshshell.run "https://open.spotify.com/search/peace"

else
if Input1 = "Calculator" OR Input1 = "calculator" OR Input1 = "Calc" OR Input1 = "calc" OR Input1 = "verify" then
Sapi.speak "Opening Calculator"
wshshell.run "calc"

else
if Input1 = "Search" OR Input1 = "search" OR Input1 = "web" OR Input1 = "google"then
Sapi.speak "Opening Google"
wshshell.run "https://www.google.com"

else
if Input1 = "About VARS" OR Input1 = "tell me about the restaurant" OR Input1 = "Tell me about the restaurant" OR Input1 = "tell me about restaurant" then
Sapi.speak "VARS Restaurant is an exquisite restaurant that will meet every taste of the customer. In our restaurant, you can try quality dishes cooked by the owner and his team. Fresh seasonal products are available on every menu. The restaurant is open from 08:00 to 23:00. Meals are served from 12:00 to 14:00 and from 18:30 to 21:00."
end if
end if
end if
end if
end if

else
Sapi.speak "Very Well!! Please enjoy your time."
end if

