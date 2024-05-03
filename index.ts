import { appendFile } from "node:fs/promises";
const config = {
  practice: 16,
  contestRange: {
    start: 1077,
    end: 1450,
  },
  gymRange: {
    start: 1600,
    end: 1800,
  },
  atcodder: {
    startingContest: 100,
    endingContest: 300,
  },
  users: ["pahad_charas_chai"],
};
const practice = config.practice;
const users = config.users;

function randomNumber(min: number, max: number) {
  return Number(Math.floor(Math.random() * (max - min) + min));
}
const atcoderDB = Bun.file("./AtcodderSelected.txt");
const atcoderDBText = await atcoderDB.text();
const problems = atcoderDBText.split("\n");
const writer = atcoderDB.writer();

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
const getSumisionId = (s) => {
  return s.problem.contestId + ":" + s.problem.index;
};
try {
  const data = await fetch("https://codeforces.com/api/problemset.problems");
  const allProblems = await data.json();

  const usersSubmissions = await Promise.all(
    users.map((user) =>
      fetch(`https://codeforces.com/api/user.status?handle=${user}&from=1`)
    )
  );
  const usersSubmissionsInJson = await Promise.all(
    usersSubmissions.map((s) => s.json())
  );

  const rawSubmissions = usersSubmissionsInJson.map((s) => s.result);
  const rawProblems = allProblems.result.problems;
  const gym_starting_range = config.gymRange.start;
  const gym_ending_range = config.gymRange.end;
  const lastContest = config.contestRange.end;

  const starting_contest = config.contestRange.start;

  let userSubmissionMap = {};
  rawSubmissions.forEach((sd) => {
    sd.forEach((s) => {
      if (
        s.verdict == "OK" &&
        s.problem.rating >= gym_starting_range &&
        s.problem.rating <= gym_ending_range
        // || s.problem.rating == 1500
      ) {
        userSubmissionMap[getSumisionId(s)] = s;
      }
    });
  });
  let nonPracticeSet = Object.values(userSubmissionMap);

  let notSolved = rawProblems.filter((c) => {
    return (
      c.contestId >= starting_contest &&
      c.contestId <= lastContest &&
      c.rating <= gym_ending_range &&
      c.rating >= gym_starting_range
    );
  });

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
  let atcoderRandomProblem = randomNumber(
    config.atcodder.startingContest,
    config.atcodder.endingContest
  );
  const actask = "d";
  const problemIdentifier = `${atcoderRandomProblem}`;
  function isProblemExist(p) {
    return problems.includes(p);
  }
  while (isProblemExist(problemIdentifier)) {
    atcoderRandomProblem = randomNumber(
      config.atcodder.startingContest,
      config.atcodder.endingContest
    );
  }

  await appendFile("./AtcodderSelected.txt", problemIdentifier + "\n");

  const atcoderProblem = `https://atcoder.jp/contests/abc${atcoderRandomProblem}`;

  console.log("Today's problems:");
  console.log(
    `https://codeforces.com/contest/${problem2.contestId}/problem/${
      problem2.index
    } of rating ${problem2.rating} ${
      rating2problems[gym_ending_range + ""].length
    }[${r2 + 1}]`
  );
  console.log(
    `https://codeforces.com/contest/${problem1.contestId}/problem/${
      problem1.index
    } of rating ${problem1.rating}  ${
      rating2problems[gym_starting_range + ""].length
    }[${r1 + 1}]`
  );
  console.log(`${atcoderProblem} of ABC-${atcoderRandomProblem}`);
} catch (e) {
  console.log("error occured", e);
}
