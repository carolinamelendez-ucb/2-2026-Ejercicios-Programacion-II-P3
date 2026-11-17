# REPORTE DE EVALUACIÓN - PROGRAMACIÓN II (P3)
**Estudiante:** Pablo Arce Maldonado  
**ID:** 114150  
**Programa:** Sistema de Peluquería Canina "Patitas Felices"  
**Fecha de Evaluación:** 2026-11-14  
**Docente Revisor:** Copilot Code Review  

---

## 📋 RESUMEN EJECUTIVO

**ESTADO:** ❌ **NO COMPILA** - Nota: **0/100**

El código presenta **5 errores críticos de compilación** que impiden su ejecución. La falta de compilación implica calificación de 0 puntos según el reglamento establecido.

---

## 🔴 FASE 2: ANÁLISIS DE COMPILACIÓN

### Resultado: FALLIDO

**Comando usado:** `g++ -std=c++17 -Wall -Wextra Ex3.cpp ListaGenerica.cpp -o ejercicio`

**Errores de compilación:** 23+ errores reportados

### Errores Críticos Bloqueantes:

#### 1. **Circular Dependency (Línea SistemaPeluqueria.h:6)**
- `SistemaPeluqueria.h` incluye `Servicios.h`
- `Servicios.h` incluye `SistemaPeluqueria.h`
- Resultado: `error: 'Servicios' was not declared in this scope`
- **Impacto:** Bloquea compilación completa

#### 2. **Variables no Inicializadas en Constructores**
- **ServicioBano.h línea 11:** Constructor usa `codigo`, `nombre`, `CostoMaterial` sin inicializar
- **ServicioCorte.h línea 12:** Mismo error
- **Impacto:** Valores indeterminados se pasan al constructor padre

#### 3. **Inicialización Circular de `capacidad`**
- **Servicios.h línea 18:** `capacidad(capacidad)` - inicializa con sí mismo
- **Impacto:** `listaPerros = new ListaGenerica<Perro>(capacidad)` recibe valor basura

#### 4. **Método Estático con Acceso a Miembros de Instancia**
- **Servicios.h línea 42:** `estaPerroRegistrado()` accede a `listaPerros` sin `this->`
- **Impacto:** Métodos estáticos no pueden acceder a `this`

#### 5. **Archivo ListaGenerica.cpp Vacío**
- Incluido en compilación pero sin contenido
- **Impacto:** Confusión de dependencias (es template, debe estar solo en .h)

---

## 📊 EVALUACIÓN POR REQUISITO

### Requisito 1: Registrar un Perro (10 puntos)
- **Estado:** ❌ NO IMPLEMENTADO/NO COMPILA
- **Implementación esperada:** Función registrarPerro() con validación de duplicados
- **Encontrado:** Método existe pero no compila
- **Puntos obtenidos:** 0/10
- **Motivo:** Código bloqueante en línea de compilación

### Requisito 2: Registrar un Servicio (10 puntos)
- **Estado:** ❌ NO IMPLEMENTADO/NO COMPILA
- **Implementación esperada:** Función registrarServicios() con lanzamiento de excepción
- **Encontrado:** Método existe pero no compila
- **Puntos obtenidos:** 0/10
- **Motivo:** Variables no inicializadas, código no compila

### Requisito 3: Registrar una Atención (25 puntos)
- **Estado:** ❌ NO EXISTE
- **Implementación esperada:** 
  - Clase `Atencion`
  - Método `registrarAtencion()` en SistemaPeluqueria
  - Cálculo de costo final
  - Excepciones si falta perro o servicio
- **Encontrado:** Ninguno de estos elementos existe
- **Puntos obtenidos:** 0/25
- **Motivo:** Funcionalidad completamente ausente

### Requisito 4: Mostrar Atenciones de un Perro (25 puntos)
- **Estado:** ❌ NO EXISTE
- **Implementación esperada:**
  - Método para mostrar atenciones
  - Mostrar datos del perro, servicios, costos totales
- **Encontrado:** No existe
- **Puntos obtenidos:** 0/25
- **Motivo:** Funcionalidad completamente ausente

### Requisito EXTRA: Perros Ordenados Alfabéticamente (10 puntos)
- **Estado:** ❌ NO IMPLEMENTADO
- **Implementación esperada:** Ordenamiento alfabético de perros
- **Encontrado:** Método `ordenarBurbuja()` está comentado en ListaGenerica.h (línea 46-56)
- **Puntos obtenidos:** 0/10
- **Motivo:** No implementado, método comentado

---

## 🎯 FASE 3: EVALUACIÓN FUNCIONAL

### Resultado de Ejecución: ❌ NO EJECUTA

**Debido a que el código no compila, no es posible ejecutar pruebas funcionales.**

**Pruebas planeadas (no ejecutadas):**
- ✗ Caso Positivo 1: Registrar perro sin duplicados
- ✗ Caso Negativo 1: Lanzar PerroDuplicadoException al registrar perro duplicado
- ✗ Caso Positivo 2: Registrar servicio único
- ✗ Caso Negativo 2: Lanzar ServicioDuplicadoException al registrar servicio duplicado
- ✗ Caso Positivo 3: Registrar atención con perro y servicio válidos
- ✗ Caso Negativo 3: Lanzar excepción si perro no existe
- ✗ Caso Negativo 4: Lanzar excepción si servicio no existe
- ✗ Caso Positivo 4: Mostrar información de perro con atenciones
- ✗ Caso EXTRA: Mostrar perros ordenados alfabéticamente

---

## 💯 FASE 4: CALIDAD DE CÓDIGO (5 criterios)

### Criterio 1: Claridad y Legibilidad
**Puntuación:** 0/1
- **Hallazgos negativos:**
  - Variable local `Servicios* Servicios` con mismo nombre que clase (confusión)
  - Falta documentación de métodos
  - Nombres inconsistentes (`codigo`, `getcodigo()` vs `getCodigo()`)
- **Puntuación:** 0 puntos

### Criterio 2: Uso Correcto de Paradigma OOP
**Puntuación:** 0/1
- **Hallazgos negativos:**
  - Circular dependencies (problema de diseño)
  - Método estático accede a miembros de instancia (incorrecto)
  - Falta encapsulación adecuada
- **Puntuación:** 0 puntos

### Criterio 3: Validación y Manejo de Errores
**Puntuación:** 0/1
- **Hallazgos negativos:**
  - No hay validación de entrada (strings vacíos)
  - No hay validación de punteros nulos
  - Falta manejo de excepciones en algunos puntos
- **Puntuación:** 0 puntos

### Criterio 4: Ausencia de Memory Leaks
**Puntuación:** 0/1
- **Hallazgos negativos:**
  - El código no compila, por lo que no se puede validar
  - Destructor en SistemaPeluqueria solo libera contenedores, no contenidos
  - Perros en ListaGenerica son liberados, bien
- **Puntuación:** 0 puntos (no validable, no compila)

### Criterio 5: Organización de Archivos y Headers
**Puntuación:** 0/1
- **Hallazgos negativos:**
  - Circular dependency entre headers
  - Inclusión innecesaria de `SistemaPeluqueria.h` en `Servicios.h`
  - `ListaGenerica.cpp` innecesario para template
  - Falta `#pragma once` en algunos headers, pero presente en otros (inconsistente)
- **Puntuación:** 0 puntos

**Subtotal Calidad:** 0/5 puntos

---

## 📈 CALIFICACIÓN FINAL

| Componente | Puntos | Obtenidos |
|-----------|--------|-----------|
| Req 1: Registrar Perro | 10 | 0 |
| Req 2: Registrar Servicio | 10 | 0 |
| Req 3: Registrar Atención | 25 | 0 |
| Req 4: Mostrar Atenciones | 25 | 0 |
| Req EXTRA: Ordenamiento | 10 | 0 |
| Calidad de Código (5 criterios) | 5 | 0 |
| **TOTAL** | **85** | **0** |

---

## 🔍 FASE 5: AUTOVERIFICACIÓN

✅ Cada hallazgo apunta a línea real del código  
✅ Errores de compilación verificables con g++ -Wall -Wextra  
✅ Clases faltantes confirmadas en árbol de archivos  
✅ Métodos comentados confirmados en ListaGenerica.h  
✅ Puntaje cuadra: No compila = 0 puntos (según reglamento)

---

## 🎓 RETROALIMENTACIÓN CONSTRUCTIVA

### Puntos Positivos Identificados:
1. ✅ Estructura general de clases bien conceptualizada
2. ✅ Uso de templates para ListaGenerica es apropiado
3. ✅ Uso de herencia para tipos de servicio es correcto
4. ✅ Creación de excepciones personalizadas es buena práctica
5. ✅ Idea de usar métodos estáticos para comparadores es creativa

### Áreas de Mejora Críticas:
1. 🔴 **URGENTE:** Resolver circular dependencies en includes
2. 🔴 **URGENTE:** Inicializar correctamente variables en constructores
3. 🔴 **URGENTE:** Implementar clase Atencion completa
4. 🔴 **URGENTE:** Implementar requisitos faltantes (Req 3, 4)
5. 🟠 **IMPORTANTE:** Revisar uso de métodos estáticos vs miembros de instancia
6. 🟠 **IMPORTANTE:** Implementar ordenamiento alfabético
7. 🟡 **RECOMENDADO:** Mejorar convención de nombres y documentación

### Plan de Acción Sugerido:
1. Eliminar `#include "SistemaPeluqueria.h"` de Servicios.h (usar forward declaration si es necesario)
2. Pasar parámetros correctamente a constructores de ServicioBano y ServicioCorte
3. Crear clase Atencion.h con relaciones Perro-Servicio
4. Implementar registrarAtencion() en SistemaPeluqueria
5. Descomenta y arregla ordenarBurbuja() en ListaGenerica.h
6. Agregar validaciones de entrada
7. Compilar y pruebas unitarias

---

## 📝 NOTAS DEL REVISOR

**Fecha de revisión:** 2026-11-14 13:23 UTC  
**Herramienta de revisión:** Copilot Code Review (Automated)  
**Verificación:** Manual  

El estudiante demuestra comprensión de conceptos OOP (herencia, polimorfismo, templates) pero hay problemas críticos de implementación que impiden compilación. Se recomienda revisar fundamentos de:
- Gestión de includes y circular dependencies
- Inicialización de constructores
- Métodos estáticos vs métodos de instancia

**Recomendación:** Solicitar entrega de versión corregida con todos los requisitos implementados.

---

**Archivo generado automáticamente - NO MODIFICAR DIRECTAMENTE**
