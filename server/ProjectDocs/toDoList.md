Main Modules to realize:

***

* Game
	* Register
		:: make new account
	* Authorization
		:: required to access the app 
	* Local Play
		:: basic game modes
		* Training mode
			:: Some info how to type efficiently
		* Basic Mode
			:: mode for training via game
		* Infinite Mode 
			:: mode with the speedup in the process
	* Multiplayer
		:: compete game modes
		* Tournament
			:: 16(?) players in the bracket every 50 symbols - last half of players - deleted
		* Lobbies to compete other players
			:: like basic mode but with others progress and target is to get first place
***

* Server
	 :: global processes
	* Multiplayer connections
		:: set data transfer between clients in the same lobby
	* Generating data for every game mode
		:: modules to track users performance and give tasks in comparable to users knowledge difficulty 
	* Data transfer to the DB
		:: databases gate
	* Authorization, Access control
		:: roles inside of app
		* admin-access
			:: admin functions
			* monitoring 
				:: check app & environment status
				* overheating
				* performance
				* RAM, CPU for each server and app - container
				* network status and events
			* logging
				:: print all events to a log to track errors
			* emergency functions
				:: functions to rescue server from any danger event
				* emergency shutdown
				* emergency reboot
				* emergency access restrict
				* emergency close global networking
				* emergency save data
		* user access
			:: user experience
			* access to all game modes
			* access to managing account stats and settings
***

* Database
	* Authorization
	  :: save hashed logins and passwords in hashed format in different databases containers. No admin-panel inside of basic user client.
		* User
		* Admin
	* progress saving
		:: global data for every user in total
		*  leader boards for every game mode separately
	* User Data
		:: User profile data and achievements

