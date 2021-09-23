#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

void SwitchOpciones (int opcion);
int MenuOpciones (void);
int MenuOpciones1 (float numero1);
int MenuOpciones2 (float numero1, float numero2);
int MenuOpciones3(float numero1, float numero2);
float IngresarOperando (char mensaje[]);
float Sumar (float primerNumero, float segundoNumero);
float Restar (float primerNumero, float segundoNumero);
void Dividir (float primerNumero, float segundoNumero);
float Multiplicar (float primerNumero, float segundoNumero);
void Factorial (float numero);

#endif /* BIBLIOTECA_H_ */
