#declare longcone = difference {
	cylinder {
		<0, 0, 0>
		<0, 0, 234>
		// x-radius is 4
		4
		// y-radius is 3
		scale y*0.75
	}
	cylinder {
		<0, 0, 1>
		<0, 0, 234>
		// x-radius is 4
		3
		// y-radius is 3
		scale y*0.75
		translate y*1
	}
	box {
		<-4, 0, -0.001>
		<4, 3, 234.01>
		scale x*1.001
	}
	texture { whitePart }
}

#declare shortcone = cylinder {
	<0, 0, 1>
	<0, 0, 233>
	1.0
	texture {
    pigment {color White }
    finish {ambient .8 diffuse .6 }
  }
}
	
/* longcone with two shortcone lights */
#declare full = union {
	object { longcone }

	object { shortcone
		translate x*1.5
	}
	object { shortcone
		translate x*-1.5
	}	
	// move, s.t 0 is at the center
	translate z*-116
}

#declare lamp = light_source {
	// put it in the center
	<0, 0, 116>
	color Gray75
	fade_distance 50
	fade_power 1
	area_light <0, 0, -116>, <0, 0, 116>, 4, 4
	adaptive 1
	jitter
	looks_like { full }	
	// rotate s.t it's facing right 
	rotate y*90
	// move to to correct x 
	// move to height 91 + y-raidus 3
	translate x*72
	translate y*94
}

#declare lamps = union {
	object { lamp translate z*84 }
	object { lamp translate z*156 } 
	object { lamp translate z*228 } 
}