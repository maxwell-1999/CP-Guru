const data = {
  name_first: "amit",
  name_second: "anil",
  age: 34,
  health_weight: 321,
  health_height: 21,
  hobby_0: "reading",
  hobby_1: "writing",
};
const result = {
  name: {
    first: "amit",
    second: "anil",
  },
  age: 34,
  health: {
    weight: 321,
    height: 21,
  },
  hobby: {
    "0": "reading",
    "1": "writing",
  },
};

const objectify = (key, value) => {
  const splittedKeys = key.split("_");
  if (splittedKeys.length == 1) {
    return { [key]: value };
  } else {
    let ans = {};
    let ref = ans;
    for (let i = 0; i < splittedKeys.length - 1; i++) {
      ref[splittedKeys[i]] = {};
      ref = ref[splittedKeys[i]];
    }
    ref[splittedKeys[splittedKeys.length - 1]] = value;
    return ans;
  }
};
const merge = (obj, to) => {
  let key = Object.keys(obj)[0];
  if (typeof obj[key] != "object") {
    to[key] = obj[key];
  } else {
    if (key in to) {
    } else {
      let l = {};
      if (!Number.isNaN(+Object.keys(obj[key])[0])) {
        l = [];
      }
      to[key] = l;
    }
    merge(obj[key], to[key]);
  }
  return to;
};

// console.log(objectify("name_second_1", 21));

let ans = {};
for (let key in data) {
  let res = objectify(key, data[key]);
  merge(res, ans);
}
console.log(ans);
