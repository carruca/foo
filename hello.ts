"use strict";

let myName = "Alice";

function getFavoriteNumber() {
	return 26;
}

function greet(person, date) {
	console.log("Hello ".concat(person, ", today is ").concat(date.toDateString(), "!"));
}

greet(getFavoriteNumber(), new Date());

const names = ["Alice", "Bob", "Eve"];

// contextual typing
names.forEach((s) => {
	console.log(s.toUpperCase());
});

function printCoord(pt: { x: number, y: number }) {
	console.log("The coordinate's x value is " + pt.x);
	console.log("The coordinate's y value is " + pt.y);
};

printCoord({ x: 3, y: 7 });

function printName(obj: { first: string, last?: string }) {
	console.log("My first name is " + obj.first + ".");
	if (obj.last !== undefined) {
		console.log("My last name is " + obj.last + ".");
	} else {
		console.log("I do not have last name.");
	}
	console.log(obj.last?.toUpperCase());
}

printName({ first: "Bob" });
printName({ first: "Alice", last: "Alisson" });


function printId(id: number | string) {
	if (typeof id == "string") {
		console.log("Your ID is: " + id.toUpperCase());
	} else {
		console.log("Your ID is: " + id);
	}
}

printId(101);
printId("202");

function welcomePeople(x: string[] | string) {
	if (Array.isArray(x)) {
		console.log("Hello, " + x.join(" and "));
	} else {
		console.log("Welcome lone traveler " + x);
	}
}

welcomePeople(["Bob", "Alice", "Eve"]);
welcomePeople("");

type Point = {
	x: number;
	y: number;
};

function printCoordPoint(pt: Point) {
	console.log("The coordinate's x value is " + pt.x);
	console.log("The coordinate's y value is " + pt.y);
};

printCoordPoint({ x: 34, y: 9 });

type ID = number | string;

function printIdType(id: ID) {
	if (typeof id == "string") {
		console.log("Your ID is: " + id.toUpperCase());
	} else {
		console.log("Your ID is: " + id);
	}
}

printIdType(2128);
printIdType("872");

function liveDangerously(x?: number | undefined) {
	console.log(x!.toFixed());
}

liveDangerously(12);

function padLeft(padding: number | string, input: string): string {
//	throw new Error("Not implemented yet!");
	if (typeof padding === "number") {
		return " ".repeat(padding) + input;
	}
	return padding + input;
}

console.log(padLeft(6, "padding left"));
console.log(padLeft("------", "padding left"));

function printAll(strs: string | string[] | null) {
	if (strs !== null) {
		if (typeof strs === "object") {
			for (const s of strs) {
				console.log(s);
			}
		} else if (typeof strs == "string") {
			console.log(strs);
		}
	}
}

printAll("Welcome to Madrid");
printAll(null);

interface Container {
	value: number | null | undefined;
}

function multiplyValue(container: Container, factor: number) {
	if (container != null) {
		return container.value *= factor;
	}
}

let c1: Container = {
	value: 2
};

let c2: Container = {
	value: null
};

console.log("The result number is " + multiplyValue(c1, 12));
console.log("The result number is " + multiplyValue(c2, 12));

type Fish = { swim: () => void };
type Bird = { fly: () => void };
type Human = { swim?: () => void; fly?: () => void };

function move(animal: Fish | Bird | Human) {
	if ("swim" in animal) {
		console.log("I can swim");
	} else {
		console.log("I can't swim, but I can fly");
	}
}

function logValue(x: Date | string) {
	if (x instanceof Date) {
		console.log(x.toUTCString());
	} else {
		console.log(x.toUpperCase());
	}
}
