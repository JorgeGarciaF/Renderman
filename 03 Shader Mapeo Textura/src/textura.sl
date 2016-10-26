surface textura(
		float Ka = 1, Kd = .5, Ks = .5, roughness = .1;
		color specularcolor = 1;
		string texturename = "";
		)
{
	color Ct = Cs;
	if (texturename != "")
		Ct *= color texture (texturename);

	normal Nf = faceforward (normalize(N), I);
	vector V = -normalize(I);
	Ci = Ct * (Ka*ambient() +Kd*diffuse(Nf)) +
		 specularcolor * Ks * specular(Nf, V, roughness);
		Oi = Os;
		Ci *= Oi;
}