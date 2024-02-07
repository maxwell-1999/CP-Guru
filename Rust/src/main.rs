// Topic: External crates
//
// Requirements:
// * Display the current date and time
//
// Notes:
// * Use the `chrono` crate to work with time
// * (OPTIONAL) Read the documentation section `Formatting and Parsing`
//   for examples on how to create custom time formats
// use chrono::DateTime;
pub mod math;
pub mod string_utils;

fn main() {
    // Part 1: math functions
    let result = {
        let two_plus_two = math::add(2, 2);
        let three = math::sub(two_plus_two, 1);
        math::mul(three, three)
    };

    // Ensure we have a correct result.
    assert_eq!(result, 9);
    println!("(2 + 2 - 1) * 3 = {}", result);

    // Part 2: string functions
    let hello = {
        let msg = "hello ";
        let msg = string_utils::trim(msg);
        string_utils::capitalize(msg)
    };
    let world = {
        let msg = "world";
        string_utils::exciting(msg)
    };
    let msg = format!("{}, {}", hello, world);

    // Ensure we have a correct result.
    assert_eq!(&msg, "Hello, world!");
    println!("{}", msg);
}
