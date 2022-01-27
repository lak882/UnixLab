// work space facing south
#declare ws = union {
	object { table }
	object { chair 
	// move to middle of room
	translate x*23.5}
	object { computer 
	translate <12.25, 41, 3> }
}

// work space facing east
#declare wsE = object {
	ws
	rotate y*-90
  translate x*29
}

// work space facing west
#declare wsW = object {
	ws
	rotate y*90
	translate z*47
}

// works space facing north
#declare wsN = object {
	ws
	rotate y*180
	translate x*47
	translate z*29
}

/* set all the workspaces in their correct areas */
#declare setup = union {
	// far left tables
	#for (i, 0, 3, 1)
		object { wsE
			translate z*78
			translate z*(i*48)
		}
	#end
	// far right tables
	#for (i, 0, 3, 1)
		object { wsW
			translate x*343
			translate z*78
			translate z*(i*48)
		}
	#end
	// middle left tables
	#declare midTables = union {
		object { ws
			translate <83, 0, 96>
		}
		object { wsW
			translate <83, 0, 96+29+1>
		}
		object { wsN
			translate <83+23, 0, 96+29+47+2>
		}
		object { wsE
			translate <83+23+32, 0, 96+29-1>
		}
	}
	object { midTables }
	// middle right tables
	object { midTables translate x*(23+32+29+39) }
}