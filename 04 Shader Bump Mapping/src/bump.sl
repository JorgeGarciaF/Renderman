normal Displace(vector dir;
				string space;
				float amp;
				float truedisp;)
{
	extern point P;
	float spacescale = length(vtransform(space, dir));	
	vector Ndisp = dir * (amp / spacescale);
	P += truedisp * Ndisp;
	return normalize (calculatenormal (P + (1-truedisp)*Ndisp));
}

displacement 
emboss	(string texturename = "";
		 float Km = 1;
		 string dispspace = "shader";
		 float truedisp = 0;
		 float sstart = .1, sscale = 1;
		 float tstart = 0, tscale = 1;
		 float blur = 0; )
{
	if (texturename != ""){
		float ss = (s - sstart) / sscale;
		float tt = (t - tstart) / tscale;

		float amp = float texture (texturename[0], ss , tt, "blur", blur);

		N = Displace (normalize(N), dispspace, -Km*amp/30, truedisp);
	}
}