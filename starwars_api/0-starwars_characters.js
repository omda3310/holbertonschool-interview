#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) {
    console.error('Error fetching data:', error);
    return;
  }

  const data = JSON.parse(body);
  const characters = data.characters;

  // Function to print character names
  function printCharacterNames (index) {
    if (index >= characters.length) {
      return;
    }

    request(characters[index], (err, res, body) => {
      if (err) {
        console.error('Error fetching character data:', err);
        return;
      }

      const characterData = JSON.parse(body);
      console.log(characterData.name);
      printCharacterNames(index + 1);
    });
  }

  printCharacterNames(0);
});
