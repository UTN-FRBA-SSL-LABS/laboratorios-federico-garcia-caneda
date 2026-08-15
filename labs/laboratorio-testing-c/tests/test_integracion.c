#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void){
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};
    Producto p1 = {"Leche", 350, 2};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p1);
    ASSERT_IGUAL(1300, carrito_total(&c));
    int valor_con_descuento = carrito_descuento(1300, 10);
    ASSERT_IGUAL(1170, valor_con_descuento);
}


/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(void) {
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 100, 1};
    Producto p1 = {"Azucar", 50, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    ASSERT_IGUAL(400, carrito_total(&c));
    ASSERT_IGUAL((&c)->cantidad, MAX_ITEMS);
    carrito_agregar(&c, p1);
    ASSERT_IGUAL(450, carrito_total(&c));
    ASSERT_IGUAL((&c)->cantidad, MAX_ITEMS);
}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
