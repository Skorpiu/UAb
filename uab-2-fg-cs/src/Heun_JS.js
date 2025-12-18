/*
Fisica Geral (21048)
e-Folio B (22-23)

Rui Sousa
1901774
*/

/**
 * Efetua a integracao de Heun para o problema do pendulo real
 * @param {number} maximo Limite superior (inclusive) de tempo (s) da integracao
 * @param {number} atual Instante atual (s) da integracao
 * @param {number} passo Passo da integracao (s)
 * @param {number} theta Angulo atual
 * @param {number} omega Velocidade angular atual
 */
function integrar(maximo, atual, passo, theta, omega) {
  if (atual > maximo) {
    // Acabou a integracao
    return;
  }

  // Funcoes da integracao de heun, do texto de apoio 2
  const k1theta = omega;
  const k1omega = f(theta, omega);
  const k2theta = omega + k1omega * passo;
  const k2omega = f(theta + k1theta * passo, omega + k1omega * passo);

  console.log(
    `${atual.toFixed(1)} ${theta.toFixed(4)} ${omega.toFixed(4)} ${k1theta.toFixed(4)} ${k1omega.toFixed(4)} ${k2theta.toFixed(4)} ${k2omega.toFixed(4)}`
  );

  // Integrar para o proximo instante (instante atual + passo)
  integrar(
    maximo,
    atual + passo,
    passo,
    theta + 0.5 * (k1theta + k2theta) * passo,
    omega + 0.5 * (k1omega + k2omega) * passo
  );
}

/**
 * Equacao diferencial do pendulo classico com arrasto
 * @param {number} theta Angulo
 * @param {number} omega Velocidade angular
 */
function f(theta, omega) {
  // Massa (kg)
  const m = 0.0026;

  // Aceleracao da gravidade (ms^-2)
  const g = 9.81;

  // Comprimento do fio (m)
  const l = 1;

  // Densidade do ar (kg/m3)
  const p = 1.28;

  // Coeficiente aerodinamico da esfera
  const cd = 0.1;

  // Raio da esfera (m)
  const raio = 0.3;

  // Area frontal da esfera
  const area = Math.PI * (raio * raio);

  // Coeficiente de arrasto
  const b = 0.5 * p * cd * area;

  // Equacao diferencial do enunciado
  return -sgn(omega) * ((b * l) / m) * (omega * omega) - (g / l) * theta;
}

/**
 * Funcao sinal
 * @param {number} x
 * @returns -1 para x < 0, 1 para x > 0, e 0 para x = 0
 */
function sgn(x) {
  if (x < 0) {
    return -1;
  }

  if (x > 0) {
    return 1;
  }

  // Se x = 0
  return 0;
}

// Executar a integracao, comecando no instante t=0,
// com angulo inicial omega = 0.05
integrar(100, 0, 0.1, 0.05, 0);
