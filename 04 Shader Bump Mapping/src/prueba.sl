surface prueba(
		uniform float Kd = 1;
		uniform float Ks = 1;
		uniform float roughness = 0.15;
		color specularColor = color(1);
		)
{
	// Variables locales
	normal Nn = normalize(N);
	vector V = -normalize(I);
	// Valores de salida
	Oi = Os;
	Ci = Oi * Cs * (
					(Kd * diffuse(Nn)) +
					(Ks * specular(Nn, V, roughness) * specularColor)
					);
}