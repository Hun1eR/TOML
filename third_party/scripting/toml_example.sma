#include <amxmodx>
#include <toml>

new Toml:g_toml;

public plugin_init()
{
    g_toml = toml_open("addons/amxmodx/configs/toml_example.toml");

    get_value();
    set_value();
    arrays();
    remove();
    init();

    toml_close(g_toml);
}

get_value()
{
    // Getting a string:
    new szString[32];
    toml_get_string(g_toml, "title", szString, charsmax(szString));

    // Getting an integer:
    new Toml:database = toml_get_table(g_toml, "database");
    new connectionMax = toml_get_int(database, "connection_max");

    // Getting an integer with a composite key:
    connectionMax = toml_get_int(g_toml, "database.connection_max");

    // Getting an integer value as a floating-point value (implicit conversion):
    new Float:flConnectionMax = toml_get_float(g_toml, "database.connection_max");

    server_print("title = ^"%s^"", szString);
    server_print("connection_max = %d", connectionMax);
    server_print("connection_max (float) = %f", flConnectionMax);
}

set_value()
{
    // Setting a string:
    toml_set_string(g_toml, "title", "Hello, TOML!");

    // Setting an integer:
    new Toml:database = toml_get_table(g_toml, "database");
    toml_set_int(database, "connection_max", 4321);

    // Setting an integer with a composite key:
    toml_set_int(g_toml, "database.connection_max", 1234);

    // Saving TOML to a file:
    toml_save(g_toml, "addons/amxmodx/configs/example_setvalue.toml");
}

arrays()
{
    new TomlArray:ports = toml_get_array(g_toml, "database.ports");
    new arraySize = toml_array_get_count(ports);

    for (new i = 0; i < arraySize; i++)
        server_print("%d", toml_array_get_int(ports, i));
}

remove()
{
    // Removing a "title" key:
    toml_remove(g_toml, "title");

    // Removing an "alpha" table:
    toml_remove(g_toml, "servers.alpha");

    // Clearing a "clients" table
    new Toml:clients = toml_get_table(g_toml, "clients");
    toml_clear(clients);

    // Clearing a "ports" array
    new TomlArray:ports = toml_get_array(g_toml, "database.ports");
    toml_clear(ports);

    // Saving TOML to a file:
    toml_save(g_toml, "addons/amxmodx/configs/example_remove.toml");
}

init()
{
    // Creating a new main table
    new Toml:root = toml_init_root();

    // Adding table to a main table
    new Toml:hello = toml_init_table(root, "hello_world");

    // Adding key "string" into "hello_world" table
    toml_init_string(hello, "string", "UTF-8 strings should work even on AMXX 1.8.2");

    // Adding key "pi" into "hello_world" table
    toml_init_float(hello, "pi", M_PI);

    // Adding array
    new TomlArray:array = toml_init_array(hello, "array");

    // Adding values to array
    for (new i = 0; i < 10; i++)
        toml_array_init_int(array, i);

    // Arrays are heterogeneous.
    toml_array_init_string(array, "You can mix any types (including tables and nested arrays) in one array")

    // Saving TOML to a file:
    toml_save(root, "addons/amxmodx/configs/example_init.toml");

    // Closing the main handle (all child handles will be closed too).
    toml_close(root);
}
