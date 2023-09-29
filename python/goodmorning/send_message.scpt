on run {targetPhone, messageText}
	tell application "Messages"
		set targetService to 1st service whose service type = iMessage
		set targetBuddy to buddy targetPhone of targetService
		send messageText to targetBuddy
	end tell
end run
