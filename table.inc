#declare foot = union {
	difference {
		box {
			<0, 0, 0>
			<3, 2, 24>
		}
		box {
			<-1, 0, 0>
			<4, 2, 5>
			rotate x*-10
			translate y*1
		}
	}
	
	box {
		<0, 0, 0>
		<2, 22, 8>
		// (3-2)/2 = 0.5
		translate <0.5, 2, 14>
	}
	texture { greyPart }
}
#declare poles = union {
	// small pole
	box {
		<0, 0, 0>
		<0.5, 15, 1.5>
		// (3-0.5)/2 = 1.25
		translate <1.25, 24, 15>
	}
	// large pole
	box {
		<0, 0, 0>
		<1, 15, 2>
		translate <1.25, 24, 17>
	}
	texture { pigment {color Black} finish {reflective} }
}
#declare underTableConnection = box {
	<0, 0, 0>
	<2, 0.5, 24>
	translate <0.5, 15+22+2, -1>
	texture { pigment {color Black} finish {reflective} }
}

#declare leg = union {
	object { foot }
	object { underTableConnection }
	object { poles }
}

#declare legConnection = union {
	box {
		<0, 0, 0> <40, 11, 3>
		texture { greyPart }
		// label of table
		texture { pigment { image_map {
			png "text/table_text.png" once
			interpolate 2
		} scale <4, 5, 0> translate <31, 5, -2> } }
	}
	// kob of table
	union {
		cylinder {
			<0, 0, 0> <0, 0, -0.5> 1
		}
		cylinder {
			<0, 0, -0.5> <0, 0, -2> 0.5
		}
		cylinder {
			<0, 0, -2> <0, 0, -3> 2
		}
		texture { silverPart }
		translate <33, 6, 0>
	}
	translate <4, 11, 20>
}

#declare tableTop = box {
	<0, 0, 0>
	<47, 1, 29>
	translate y*40
	texture { whitePart }
}

/* full table */
#declare table = union {
	object { leg
   	translate <0.5, 0, 4>
	}
	object { leg
		// mirror
		scale <-1, 1, 1>
    // then bring back to origin
		translate x*3
    translate <42.5, 0, 4>
	}
	// connecting legs
	object { legConnection }
	object { tableTop }
	pigment { color White }
}

#declare smallLeg = union {
	object { foot }
	object { underTableConnection translate y*(-13) }
	object { poles scale y*0.2}
}

#declare smallTable = union {
	object { smallLeg
   	translate <0.5, 0, 4>
	}
	object { smallLeg
		// mirror
		scale <-1, 1, 1>
    // then bring back to origin
		translate x*3
    translate <42.5, 0, 4>
	}
	// connecting legs
	object { legConnection }
	object { tableTop translate y*(-13) }
	pigment { color White }
}
