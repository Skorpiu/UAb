<Query Kind="Program" />

/*
Física Geral (21048)
e-Fólio B

Rui Sousa
1901774
*/

void Main()
{
	Integrar(100, 0, 0.1m, 0.05m, 0);
}

// Efetua a integração de Heun para o problema do pêndulo real
public static void Integrar(decimal maximo, decimal atual, decimal passo, decimal theta, decimal omega) {
	if (atual > maximo) {
		return;
	}
	
	// Funções da integração de heun, do texto de apoio 2
	var k1teta = omega;
	var k1omega = F(atual, theta, omega);
	var k2teta = omega + (k1omega * passo);
	var k2omega = F(atual + passo, theta + (k1teta * passo), omega + (k1omega * passo));
	
	Console.WriteLine($"{atual:0.0} {theta:0.0000} {omega:0.0000} {k1teta:0.0000} {k1omega:0.0000} {k2teta:0.0000} {k2v:0.0000}");
	
	Integrar(maximo, atual + passo, passo, theta + (0.5m * (k1teta + k2teta) * passo), omega + 0.5m * (k1omega + k2omega) * passo);	
}

public static decimal F(decimal t, decimal theta, decimal omega)
{
	// Massa (g)
	const decimal m = 2.6m;

	// Aceleração da gravidade (ms^-2)
	const decimal g = 9.81m;

	// Comprimento do fio (m)
	const decimal l = 1m;

	// Densidade do ar (kg/m3)
	const decimal p = 1.28m;

	// Coeficiente aerodinâmico da esfera 
	const decimal cd = 0.1m;

	// Raio da esfera (cm)
	const decimal raio = 3m;

	// Área frontal da esfera
	const decimal area = (decimal)Math.PI * (raio * raio);

	// Coeficiente de arrasto
	const decimal b = 0.5m * p * cd * area;
	
	// Equação diferencial do pêndulo clássico com arrasto
	return -Sgn(omega) * ((b * l) / m) * (omega * omega) - (g / l) * theta;
}

// Função sinal (-1 para x < 0, 1 para x > 0, e 0 para x = 0)
public static decimal Sgn(decimal x)
{
	if (x < 0)
	{
		return -1;
	}

	if (x > 0)
	{
		return 1;
	}

	// Se x = 0
	return 0;
}