fn main() {
    let  x = {a:"amot"};
    let &mut y = x;
    y.push_str(", world");
    // mutate_str(&mut x);
    println!("{} ",x); // Accessing x after modifying it through the reference
}

fn mutate_str(s: &mut String) {
    s.push_str(", world");
}