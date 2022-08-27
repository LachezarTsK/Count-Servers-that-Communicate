
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countServers = function (grid) {
    const MAX_ROWS = 250;
    const MAX_COLUMNS = 250;

    let serversInRow = new Array(MAX_ROWS + 1).fill(0);
    let serversInColumn = new Array(MAX_COLUMNS + 1).fill(0);

    for (let r = 0; r < grid.length; ++r) {
        for (let c = 0; c < grid[0].length; ++c) {
            if (grid[r][c] === 1) {
                ++serversInRow[r];
                ++serversInColumn[c];
            }
        }
    }

    let connectedServers = 0;
    for (let r = 0; r < grid.length; ++r) {
        for (let c = 0; c < grid[0].length; ++c) {
            if (grid[r][c] === 1 && (serversInRow[r] > 1 || serversInColumn[c] > 1)) {
                ++connectedServers;
            }
        }
    }
    return connectedServers;
};
