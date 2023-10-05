import axios from "axios";
function randomNumber(min: number, max: number) {
  return Number(Math.floor(Math.random() * (max - min) + min));
}
try {
  const data = await fetch("https://codeforces.com/api/problemset.problems");
  const d = await data.json();
  const dd = await fetch(
    "https://codeforces.com/api/user.status?handle=pahad_charas_chai&from=1"
  );
  const ssss = await dd.json();
  const rawSubmissions = ssss.result;
  const rawProblems = d.result.problems;
  const gym_starting_range = 1400;
  const gym_ending_range = 1500;
  const starting_contest = 1220;
  const nonPracticeSet = rawSubmissions.filter((s) => {
    return (
      s.verdict == "OK" &&
      (s.problem.rating == 1400 || s.problem.rating == 1500)
    );
  });
  const gymProblems = rawProblems.filter((c) => {
    const isPossible =
      c.contestId >= starting_contest &&
      c.contestId <= 1830 &&
      (c.rating == 1400 || c.rating == 1500);
    let isNotSolved = true;
    for (const np of nonPracticeSet) {
      //   console.log(np.contestId, c.contestId, np.name, c.name);
      if (np.problem.contestId == c.contestId && np.problem.name === c.name) {
        isNotSolved = false;
        break;
      }
    }
    // console.log(`isNotSolved: `, isNotSolved);

    return isPossible && isNotSolved;
  });

  //   console.log(`nonPracticeSet: `, nonPracticeSet.length, gymProblems.length);
  const problem = gymProblems[randomNumber(0, gymProblems.length - 1)];
  console.log(
    `https://codeforces.com/contest/${problem.contestId}/problem/${problem.index}`
  );
} catch (e) {
  console.log("error occured", e);
}
