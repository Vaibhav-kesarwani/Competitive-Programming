function solve() {
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    const N = 5010;
    let dp = Array.from(Array(N), () => Array(N).fill(-1));
    let ct = Array(N).fill(0);

    function r(i, asc) {
        if (asc < 0) return -2;
        if (i === 0) return asc ? -2 : 0;
        if (dp[i][asc] !== -1) return dp[i][asc];

        if (ct[i]) dp[i][asc] = r(i - 1, asc - 1);
        else dp[i][asc] = r(i - 1, asc);

        if (r(i - 1, asc) !== -2 && r(i - 1, asc) + ct[i] <= asc) {
            if (dp[i][asc] === -2 || r(i - 1, asc) + ct[i] < dp[i][asc]) {
                dp[i][asc] = r(i - 1, asc) + ct[i];
            }
        }

        return dp[i][asc];
    }

    let input = [];
    rl.on('line', (line) => {
        input.push(line.trim());
    });

    rl.on('close', () => {
        let index = 0;
        const tc = parseInt(input[index++]);

        for (let t = 0; t < tc; t++) {
            const n = parseInt(input[index++]);

            for (let i = 0; i <= n; i++) {
                dp[i].fill(-1);
            }

            for (let i = 0; i < n; i++) {
                const x = parseInt(input[index++]);
                ct[x]++;
            }

            let ans = n;
            for (let i = n; i >= 0; i--) {
                if (r(n, i) !== -2) {
                    ans = i;
                    break;
                }
            }

            console.log(ans);

            ct.fill(0);
        }
    });
}

solve();
