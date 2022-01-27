/* matte gray */
#declare greyPart = texture {
	pigment {
		color rgb<0.2, 0.2, 0.2>
	}
}

/* matte white */
#declare whitePart = texture {
	pigment {
		color Wheat
	} 
}

#declare wallPart = texture {
	pigment {
		color White
	}
}

#declare silverPart = texture {
	Metal
}

/* metalic-type texture */
#declare reflective = finish {
    ambient 0.1
    brilliance 6
    diffuse 0.7
    metallic
    specular 0.80
    roughness 1/120
    reflection 0.05
}

#declare window =
texture{
  pigment{ rgbf<0.98,0.98,0.98,0.8>}
  finish { diffuse 0.1
           reflection 0.2
           specular 0.8
           roughness 0.0003
           phong 1
           phong_size 400}
  }