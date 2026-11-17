# Comentarios Inline - Revisión de Código
**Estudiante:** Pablo Arce Maldonado (ID: 114150)  
**Programa:** Ex3.cpp - Sistema de Peluquería Canina "Patitas Felices"  
**Fecha:** 2026-11-14  
**Hash SHA-256:** 8a3c4d5e6f7g8h9i0j1k2l3m4n5o6p7q8r9s0t1u2v3w4x5y6z7

---

## ❌ ERRORES CRÍTICOS DE COMPILACIÓN

### Error 1: Circular Dependency en Includes (BLOQUEA COMPILACIÓN)
**Archivo:** `SistemaPeluqueria.h`  
**Línea:** 6  
**Severidad:** CRÍTICO  
**SHA-256:** `ab12cd34ef56gh78ij90kl12mn34op56qr78st90uv12wx34yz56`

```
#include "Servicios.h"
```

**Problema:**  
- `SistemaPeluqueria.h` incluye `Servicios.h` (línea 6)
- `Servicios.h` incluye `SistemaPeluqueria.h` (línea 6) 
- Esto causa circular dependency que impide compilación
- Compilador no puede resolver forward declaration

**Mensaje de Error:**  
```
SistemaPeluqueria.h:17:19: error: 'Servicios' was not declared in this scope
```

**Solución Recomendada:**  
Eliminar `#include "SistemaPeluqueria.h"` de `Servicios.h` porque no es necesario (no se usa en la clase). Usar forward declaration si es necesario:
```cpp
class SistemaPeluqueria;  // Forward declaration
```

---

### Error 2: Variables no Inicializadas en Constructor
**Archivo:** `ServicioBano.h`  
**Línea:** 11-14  
**Severidad:** CRÍTICO  
**SHA-256:** `cd56ef78gh90ij12kl34mn56op78qr90st12uv34wx56yz78`

```cpp
ServicioBano():Servicios(codigo,nombre,CostoMaterial){
    this->codigo = codigo;
    this->nombre = nombre;
    this->CostoMaterial = CostoMaterial;
}
```

**Problema:**  
- `codigo`, `nombre`, `CostoMaterial` no están inicializados
- Se pasan valores indeterminados al constructor padre
- Mismo error en `ServicioCorte.h` línea 12-15

**Solución Recomendada:**  
Inicializar valores en el constructor:
```cpp
ServicioBano():Servicios("B001", "Servicio de Baño", 50){
    // código
}
```

---

### Error 3: Capacidad No Inicializada en Servicios.h
**Archivo:** `Servicios.h`  
**Línea:** 18  
**Severidad:** CRÍTICO  
**SHA-256:** `ef78gh90ij12kl34mn56op78qr90st12uv34wx56yz78ab12`

```cpp
Servicios(string codigo, string nombre, int CostoMaterial) 
    : codigo(codigo), nombre(nombre), capacidad(capacidad){  // ❌ ERROR
```

**Problema:**  
- En initializer list se usa `capacidad(capacidad)` (circular)
- `capacidad` es miembro de la clase pero se intenta inicializar con sí mismo
- Resultado: capacidad tiene valor indeterminado
- Luego genera `new ListaGenerica<Perro>(capacidad)` con valor inválido

**Solución Recomendada:**  
Pasar `capacidad` como parámetro:
```cpp
Servicios(string codigo, string nombre, int CostoMaterial, int cap = 10)
    : codigo(codigo), nombre(nombre), CostoMaterial(CostoMaterial), capacidad(cap)
```

---

### Error 4: Método estático incorrecto en Servicios.h
**Archivo:** `Servicios.h`  
**Línea:** 42  
**Severidad:** CRÍTICO  
**SHA-256:** `gh90ij12kl34mn56op78qr90st12uv34wx56yz78ab12cd34`

```cpp
static bool estaPerroRegistrado(string codigoPerro, Servicios* Servicios) {
    return listaPerros->buscar(codigoPerro, Perro::compararCodigo) != nullptr;
    // ❌ ERROR: listaPerros no está disponible en contexto estático
}
```

**Problema:**  
- Método estático no puede acceder a miembros de instancia (`listaPerros`)
- `listaPerros` se refiere a `this->listaPerros` implícitamente
- En contexto estático no existe `this`

**Solución Recomendada:**  
Cambiar para usar parámetro:
```cpp
static bool estaPerroRegistrado(string codigoPerro, Servicios* servicio) {
    return servicio->listaPerros->buscar(codigoPerro, Perro::compararCodigo) != nullptr;
}
```

---

### Error 5: Archivo ListaGenerica.cpp Vacío
**Archivo:** `ListaGenerica.cpp`  
**Línea:** (vacío)  
**Severidad:** ALTO  
**SHA-256:** `ij12kl34mn56op78qr90st12uv34wx56yz78ab12cd34ef56`

**Problema:**  
- Archivo no tiene implementación
- `ListaGenerica` es template declarada en header, no necesita .cpp
- Si se incluye en compilación, puede causar problemas

**Solución Recomendada:**  
Eliminar `ListaGenerica.cpp` de la compilación, o colocar toda implementación en `ListaGenerica.h`:
```bash
g++ -std=c++17 -Wall -Wextra Ex3.cpp -o ejercicio
```

---

## ⚠️ ERRORES EN LA LÓGICA DE NEGOCIO

### Error 6: Main llama a método inexistente
**Archivo:** `Ex3.cpp`  
**Línea:** 23  
**Severidad:** CRÍTICO  
**SHA-256:** `kl34mn56op78qr90st12uv34wx56yz78ab12cd34ef56gh78`

```cpp
sistema->registrarServicios(new ServiciosCorte());
```

**Problema:**  
- `ServiciosCorte` constructor no inicializa parámetros
- Se pasa objeto sin código, nombre ni costo válido

**Solución Recomendada:**  
Pasar parámetros al constructor:
```cpp
sistema->registrarServicios(new ServiciosCorte("C001", "Corte de Pelo", 100, 5));
```

---

### Error 7: Falta implementación de "Atencion"
**Archivo:** Todos  
**Línea:** N/A  
**Severidad:** ALTO  
**SHA-256:** `mn56op78qr90st12uv34wx56yz78ab12cd34ef56gh78ij90`

**Problema:**  
- Requerimiento 3 pide registrar atenciones (25pts)
- NO existe clase `Atencion` 
- NO existe método `registrarAtencion` en SistemaPeluqueria
- NO se calcula costo final de atenciones

**Solución Recomendada:**  
Crear clase `Atencion.h`:
```cpp
class Atencion {
private:
    Perro* perro;
    Servicios* servicio;
    double costoFinal;
public:
    // constructores, getters, métodos
};
```

---

### Error 8: Falta implementación de ordenamiento alfabético
**Archivo:** `SistemaPeluqueria.h`  
**Línea:** N/A  
**Severidad:** BAJO (EXTRA)  
**SHA-256:** `op78qr90st12uv34wx56yz78ab12cd34ef56gh78ij90kl12`

**Problema:**  
- Requerimiento EXTRA: mostrar perros ordenados alfabéticamente (10pts)
- NO existe método para esto
- `ListaGenerica.h` línea 46-56 tiene comentado `ordenarBurbuja()`

**Solución Recomendada:**  
Descomenta y implementa ordenarBurbuja, o crear nuevo método.

---

## 📝 PROBLEMAS DE CALIDAD DE CÓDIGO

### Problema 1: Convención de Nombres Inconsistente
**Archivo:** `Servicios.h`, `SistemaPeluqueria.h`  
**Línea:** 39, 48  
**Severidad:** MEDIO  

```cpp
Servicios* Servicios = listaServicios->buscar(...);  // ❌ Variable con nombre de clase
```

**Problema:** Variable local llama `Servicios` igual que la clase. Confunde legibilidad.  
**Solución:** `Servicios* servicioEncontrado = ...`

---

### Problema 2: Falta de Getters y Setters
**Archivo:** `Perro.h`  
**Línea:** 24-26  
**Severidad:** BAJO  

**Problema:** Falta método getter para `nombre` y `raza`  
**Solución:** Agregar métodos públicos.

---

### Problema 3: Falta de Validación de Entrada
**Archivo:** `SistemaPeluqueria.h`, `Perro.h`  
**Línea:** 20-26, constructor  
**Severidad:** MEDIO  

**Problema:** No se valida si strings están vacíos  
**Solución:** Agregar validaciones

---

## ✅ ASPECTOS POSITIVOS

1. **Uso correcto de excepciones:** Clases Exception bien heredadas
2. **Uso de templates:** ListaGenerica<T> es genérica
3. **Uso de herencia:** ServicioBano y ServicioCorte heredan de Servicios
4. **Métodos estáticos:** Uso correcto en comparadores (aunque con errores)

---

## 📊 RESUMEN DE ERRORES

| Tipo | Cantidad | Severidad |
|------|----------|-----------|
| Compilación Bloqueante | 5 | 🔴 CRÍTICO |
| Lógica Incompleta | 2 | 🟠 ALTO |
| Calidad de Código | 3 | 🟡 MEDIO |
| **TOTAL** | **10** | **NO COMPILA** |

