#define ENVPARAMS         envname, envspace, envrad

#define DECLARE_ENVPARAMS                               \
        string envname, envspace; uniform float envrad

#define DECLARE_DEFAULTED_ENVPARAMS                     \
        string envname = "", envspace = "world";        \
        uniform float envrad = 1

float
raysphere ( point E; vector I;
            float r;
            float eps;
            output float t0, t1;)

{
  float b = 2 * ((vector E).I);
  float c = ((vector E).(vector E)) - r*r;
  float discrim = b*b - 4*c;
  float solutions;
  if(discrim > 0){
     discrim = sqrt(discrim);
     t0 = (-discrim -b) / 2;
     if(t0 > eps) {
        t1 = (discrim - b) / 2;
        solutions = 2;
     } else {
          t0 = (discrim - b) / 2;
          solutions = (t0 > eps) ? 1 : 0;
     }
  } else if (discrim == 0) {
      t0 = -b/2;
      solutions = (t0 > eps) ? 1 : 0;
  } else {
      solutions = 0;
  }
  return solutions;
}

color Environment( string envname, envspace; uniform float envrad;
                    point P; vector R; float blur; output float alpha;)

{
  point Psp = transform (envspace, P);
  vector Rsp = normalize (vtransform (envspace, R));
  uniform float r2 = envrad * envrad;
  if ((vector Psp).(vector Psp) > r2)
      Psp = point (envrad * normalize (vector Psp));
  float t0, t1;
  if(raysphere (Psp, Rsp, envrad, 1.0e-4, t0, t1) > 0)
      Rsp = vector (Psp + t0 * Rsp);
  alpha = float environment (envname[3], Rsp, "blur", blur, "fill", 1);
  return  color environment (envname, Rsp, "blur", blur);
}


color
ReflMap ( string reflname; point P; float blur;
          output float alpha; )
{
  point Pndc = transform ("NDC" , P);
  float x = xcomp(Pndc), y = ycomp(Pndc);
  alpha = float texture (reflname[3], x, y, "blur", blur, "fill", 1);
  return color texture ( reflname, x, y, "blur", blur);  
}


color
SampleEnvironment (point P; vector R; float Kr, blur;
                    DECLARE_ENVPARAMS;)
{
  
  color C = 0;
  float alpha;
  if (envname != ""){
    if(envspace == "NDC")
         C = ReflMap (envname, P, blur, alpha);
    else C = Environment (envname, envspace, envrad, P, R, blur,
                          alpha);
  }
  return Kr*C;
}

color MaterialShinyPlastic(normal NF; color basecolor;
                          float Ka, Kd, Ks, roughness, Kr, blur, ior;
                          DECLARE_ENVPARAMS;)
{
  
  extern point P;
  extern vector I;
  vector IN = normalize(I), V = -IN;
  float fkr, fkt; vector R, T;
  fresnel (IN, NF, 1/ior, fkr, fkt,R, T);
  fkt = 1 - fkr;    
  return fkt * basecolor * (Ka*ambient() + Kd*diffuse(NF)) + 
                      (Ks * fkr) * specular(NF, V, roughness) +
                      SampleEnvironment(P, R, (fkr * Kr), blur, ENVPARAMS);
}

surface
shinyplastic( float Ka = 1, Kd = 0.1, Ks = 1, roughness = 0.2;
            float Kr = 0.8, blur = 0, ior = 1.5; DECLARE_DEFAULTED_ENVPARAMS; )
{
  
  normal NF = faceforward (normalize(N), I);
  Ci = MaterialShinyPlastic (NF, Cs, Ka, Kd, Ks, roughness, Kr, blur, ior,
                            ENVPARAMS);
  Oi = Os; Ci *= Oi;
}