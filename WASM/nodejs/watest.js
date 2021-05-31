/**
 * To run this programme, please execute the following command
 *
 * node watest.js
 *
 * @type {(function(*): Promise<unknown>)|{Module?: function(*): Promise<unknown>}}
 */


var factory = require("./js_api.js")

factory().then((instance) => {
    instance._sayHi();
    instance.ccall("sayHi");
    console.log(instance._daysInWeek());
});

