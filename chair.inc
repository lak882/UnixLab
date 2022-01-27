#declare bluePart = texture {
  normal { bump_map { gif "text/fabricbumps.gif" bump_size 10 } scale 0.17 }
  finish { diffuse 0.8 specular 0.2 }
	pigment { color rgb<0.05, 0.15, 0.23> }
}

#declare pancake = union {
	// cylinder with radii x=7, y=7, z=1
	cylinder { <0, 0, -1> <0, 0, 1> 7 }
	// add 1 to x, z radii and round out edges
	// minor radius = 1 agrees with z-radius
	torus { 7, 1
		rotate x*-90
	}
}

#declare back = union {
	/* horizontal panckae with radii x=8, y=8 z=1*/
	object { pancake
		scale x*(9/8)
		scale z*1.5
		texture { bluePart }
	}
	object { pancake 
		scale x*(9/8)
		scale z*0.25
		translate z*-1.5
		texture { pigment {color Black} finish {reflective} }
	}
	translate <0, 42, -10>
	
}

#declare seat = union {
	object { pancake
		rotate x*90
		scale x*(10/8)
		scale y*1.5
		texture { bluePart }
	}
	object { pancake
		rotate x*90
		scale y*0.25
		translate y*-1.5
		texture { pigment {color Black} finish {reflective} }
	}
	translate y*33
}

#declare bottom = union {
	difference {
		box { <0, 0, 0> <9, 2, 13> }
		// take out bottom slice
		box { <-0.001, 0, 0.001> <10, 2, 15> 
			translate y*-2
			rotate x*-3
		}
		// move to center
		translate x*-4.5		
	}
	difference {
		cylinder { <-2.5, 0, 0> <2.5, 0, 0> 5 }
		cylinder { <-6, 0, 0> <6, 0, 0> 4.5}
		box { <-6, 0, -6> <6, 10, 6> }
		box { <-6, -10, 0> <6, 10, 6> }
		// raidus + up on box
		translate y*5+1
	}
	texture { pigment {color Black} finish {reflective} }
	translate z*-7.5
	translate y*29
}

#declare leg = union {
	#declare roller = union {
		cylinder {
			<1, 1, 1> <1, 1, 0.2> 1
		}
		cylinder {
			<1, 1, -1> <1, 1, -0.2> 1 }
		cylinder {
			<1, 1, -0.8> <1, 1, 0.8> 0.2 }
		difference {
			cylinder { <1, 1, 1> <1, 1, -1> 1.08 }
			cylinder { <1, 1, 1.04> <1, 1, -1.04> 1.08 }
			plane { <0, 1, 0> 1 }
		}
		difference {
			cylinder { <0, 1, 0> <0, 2.04, 0> 1 }
			cylinder { <1, 1, 1.04> <1, 1, -1.04> 1.08 }
			plane { <0, 1, 0> 1 }
		}
		cylinder { <0, 2.04, 0> <0, 2.08, 0> 1}
	}
	
	difference {
		union {
			// sphere to round out the end
			sphere { 
				<9, 2.5, 0>
				0.5
			}
			cylinder { 
				<0, 2.5, 0>
				<9, 2.5, 0>
				// depth: 1.0
				0.5
			}
			// wdith: 1.5
			scale z*(0.75/0.5)
		}
		// cut off @ 2 
		plane {<0,1,0>, 2}
	}
	object {roller rotate y*60 translate x*9}
}

#declare stand = union {
	// middle part of where legs splay out from
	cylinder { <0, 2, 0>, <0, 3, 0>, 2 }
	// individual legs
	#for (i, 0, 4, 1)
		object { leg rotate y*(72*i) }
	#end
	texture { pigment {color Black} finish {reflective} }
}

#declare ring = union {
	union {
		cylinder {
			<0, 3, 0> <0, 7, 0> 1.5
		}
		#for (i, 0, 3, 1)
			box { <-0.25, 0, 0> <0.25, 0.5, 9> translate y*6.5
			rotate y*90*i}
		#end
		texture { pigment {color Black} finish {reflective} }
	}
	torus {
		9, 0.5
		translate y*6.5
		texture {silverPart}
	}
}

#declare extension = union {
	union {
		cylinder { <0,0,0> <0,5,0> 1 
			translate y*7}
		cylinder { <0,0,0> <0,5,0> 1.5
			translate y*12}
		cylinder { <0,0,0> <0,5,0> 1.25 
			translate y*17}
		cylinder { <0,0,0> <0,5,0> 1
			translate y*22}	
		texture { pigment {color Black} finish {reflective} }
	}
	cylinder { <0,0,0> <0,2,0> 0.5
		translate y*27 
		texture {silverPart} 
	}
}

#declare chair = union {
  object{ back }
  object{ seat }
	object{ bottom }
	object{ stand }
	object{ ring }
	object{ extension }
}