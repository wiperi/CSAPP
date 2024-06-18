var name = "GuitarDB";

var list = [];

var add = function(item) {
    list.push(item);
}

class Guitar {
    
    brand = "";
    model = "";
    price = 0;

    constructor(brand, model, price) {
        this.brand = brand;
        this.model = model;
        this.price = price;
    }


    getBrand() {
        return this.brand;
    }

    getModel() {
        return this.model;
    }
}