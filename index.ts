const practice = "16-u";

function randomNumber(min: number, max: number) {
  return Number(Math.floor(Math.random() * (max - min) + min));
}
function shuffle(array) {
  let currentIndex = array.length,
    randomIndex;

  // While there remain elements to shuffle.
  while (currentIndex > 0) {
    // Pick a remaining element.
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex--;

    // And swap it with the current element.
    [array[currentIndex], array[randomIndex]] = [
      array[randomIndex],
      array[currentIndex],
    ];
  }

  return array;
}
const markedText = await Bun.file("./dead_marked.txt").text();
let deadProblems = markedText
  .split("\n")
  .map(
    (s) =>
      s.substring(s.search("/contest")).split("/")[2] +
      ":" +
      s.substring(s.search("/contest")).split("/")[4]
  );
const laterText = await Bun.file("./new_ds.txt").text();
const laterProblems = laterText.split("\n").map((s) => {
  const splittedArray = s.substring(s.search("/contest")).split("/");
  s.substring(s.search("/contest")).split("/");
  return splittedArray[2] + ":" + splittedArray[4];
});
const markedProblems = deadProblems.concat(laterProblems);
console.log(`markedProblems: `, markedProblems);
try {
  const data = await fetch("https://codeforces.com/api/problemset.problems");
  const allProblems = await data.json();
  const dd = await fetch(
    "https://codeforces.com/api/user.status?handle=pahad_charas_chai&from=1"
  );
  const submissions = await dd.json();
  const rawSubmissions = submissions.result;
  const rawProblems = allProblems.result.problems;
  const range = practice.split("-");
  let num = Number(range[0]) * 100;
  console.log(`num: `, num, practice);
  const gym_starting_range = range[1] == "l" ? num : num - 100;
  const gym_ending_range = range[1] == "l" ? num + 100 : num;
  const lastContest = 1893;
  const difficulty = 1;

  const starting_contest = 1220;
  const nonPracticeSet = rawSubmissions.filter((s) => {
    return (
      s.verdict == "OK" &&
      s.problem.rating >= gym_starting_range &&
      s.problem.rating <= gym_ending_range
      // || s.problem.rating == 1500
    );
  });
  console.log(`allproblems: `, rawProblems.length);
  let notSolved = rawProblems.filter((c) => {
    return (
      c.contestId >= starting_contest &&
      c.contestId <= lastContest &&
      c.rating <= gym_ending_range &&
      c.rating >= gym_starting_range
    );
  });
  console.log(`inrange: `, notSolved.length);

  let deadFiltered = notSolved.filter((c) => {
    let isNotSolved = true;
    // remove solved
    for (const np of nonPracticeSet) {
      if (np.problem.contestId == c.contestId && np.problem.name === c.name) {
        isNotSolved = false;
        break;
      }
    }

    return isNotSolved;
  });
  console.log(`notsolved: `, deadFiltered.length);

  let gymProblems = deadFiltered.filter((c) => {
    let isNotSolved = true;

    // remove marked
    for (const markedProblem of markedProblems) {
      const [contestId, problemIndex] = markedProblem.split(":");
      if (c.contestId == contestId && c.index == problemIndex) {
        isNotSolved = false;
        break;
      }
    }

    return isNotSolved;
  });

  let rating2problems = {};
  for (let p of gymProblems) {
    if (p.rating in rating2problems) {
      rating2problems[p.rating].push(p);
    } else {
      rating2problems[p.rating] = [p];
    }
  }

  let shuffleCount = 20;
  while (shuffleCount) {
    shuffle(rating2problems[gym_starting_range + ""]);
    shuffle(rating2problems[gym_ending_range + ""]);
    shuffleCount--;
  }

  const r1 = randomNumber(
    0,
    rating2problems[gym_starting_range + ""].length - 1
  );
  const r2 = randomNumber(0, rating2problems[gym_ending_range + ""].length - 1);
  const problem1 = rating2problems[gym_starting_range + ""][r1];
  const problem2 = rating2problems[gym_ending_range + ""][r2];
  console.log(Object.keys(rating2problems));
  console.log(
    `https://codeforces.com/contest/${problem1.contestId}/problem/${
      problem1.index
    } of rating ${problem1.rating}  ${
      rating2problems[gym_starting_range + ""].length
    }[${r1 + 1}]`
  );
  console.log(
    `https://codeforces.com/contest/${problem2.contestId}/problem/${
      problem2.index
    } of rating ${problem2.rating} ${
      rating2problems[gym_ending_range + ""].length
    }[${r2 + 1}]`
  );
} catch (e) {
  console.log("error occured", e);
}
