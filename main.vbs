Set Sapi = Wscript.CreateObject("SAPI.SpVoice")
set wshshell = wscript.CreateObject("wscript.shell")

dim Input

Sapi.speak "Hello!! Welcome to VARS Restaurant, How may I help you"
Input=inputbox ("About Vars Restaurant"& vbCrLf & "Menu" & vbCrLf & "Calculator"& vbCrLf & "Want to do a random search?")

if Input = "about vars restaurant" OR Input = "About Vars Restaurant" then
Sapi.speak "VARS Restaurant is an exquisite restaurant that will meet every taste of the customer. In our restaurant, you can try quality dishes cooked by the owner and his team. Fresh seasonal products are available on every menu. The restaurant is open from 08:00 to 23:00. Meals are served from 12:00 to 14:00 and from 18:30 to 21:00."

else
if Input = "menu" OR Input = "Menu" then
Sapi.speak "Please refer to command line"


else
if Input = "google" OR Input = "Google" OR Input = "Search" OR Input = "random search"then
Sapi.speak "Opening google"
wshshell.run "www.google.com"


else
if Input = "calculator" OR Input = "Calculator" then
Sapi.speak "Opening calculator"
wshshell.run "calc"


else
if Input = "" then
else


Sapi.speak "I don't recognize your input, Please try something else"
end if
end if
end if
end if
end if