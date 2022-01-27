#declare wallBox = union {
	#declare boxWidth = -0.5;
	// outer box frame
	union {
		difference {
			box {
				<0, 0, boxWidth> <20, 20, 0>
			}
			box {
				<0, 0, -1> <18, 18, 1>
				translate <1, 1, 0>
			}
		}
		// inner box
		box {
			<0, 0, boxWidth> <17, 17, 0>
			translate <1.5, 1.5, 0>
		}
		texture { whitePart }
		texture { pigment { image_map {
			png "text/wallbox_text.png" once
		} scale <4, 1, 0> translate <8, 19, 0> } }
	}
	cylinder {
		<0, 0, -1.0> <0, 0, -0.5> 0.5
		translate <17, 9, 0>
		texture { silverPart } 
	}
	translate <0, 40, 280>
}


#declare shrank1 = union {
	// overall box with big whole in it
	difference {
		box { <0, 0, 0> <42, 65, 18> }
		box { <0, 0, -1> <40, 61, 1> 
		translate <1, 2, 0> }
	}
	// inner two doors 
	difference {
		box { <1.5, 2.5, 0> <40.5, 62.5, 1> }
		box { <19.5, 0, -1> <22.5, 65, 2> }
	}
	texture { pigment {color rgb<0.7, 0.7, 0.7>} finish {reflective} }
}

#declare shrank2 = union {
	// overall box with big whole in it
	difference {
		box { <0, 0, 0> <36, 65, 18> }
		box { <0, 0, -1> <34, 60, 1> 
		translate <1, 3, 0> }
	}
	// inner two doors 
	difference {
		box { <1.5, 3.5, 0> <34.5, 62.5, 1> }
		// inner indent
		box { <17.5, 0, -1> <18.5, 65, 2> }
		
		// two handles
		box { <0, 0, -1> <1.5, 6, 2> 
		translate <15, 27, 0> }
		box { <0, 0, -1> <1.5, 6, 2> 
		translate <19.5, 27, 0> }
	}	
	texture { pigment {color rgb<0.7, 0.7, 0.7>} finish {reflective} }
}

#declare shrank3 = difference {
	#declare space = box {
		<1, 0, -1> <34, 13, 11>
	}
	box { <0, 0, 0> <36, 48, 12> }
	object { space translate y*5 }
	object { space translate y*19 }
	object { space scale y*(14/13) translate y*33 }
	texture { pigment {color rgb<0.5, 0.5, 0.5>} finish {reflective} }
}		
#declare wall = union {
	object { wallBox translate <12, 0, -10> }
	object { wallBox translate x*47 }
	object { wallBox translate x*111 }
	object { wallBox translate x*319 }
	object { wallBox translate x*283 }
	object { wallBox translate x*245 }	
	
	object { smallTable translate <81 ,0 ,251> }
	object { shrank1 translate <144,0,262> }
  object { shrank2 translate <208,0,262> }
  object { shrank3 translate <244,0,268> }
	pigment { color White }
}
