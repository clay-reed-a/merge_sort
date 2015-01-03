

Object.defineProperties(
  Array.prototype, {
    isNotDone: { 
      get: function() {
        return !(this.length === 0)
      }},
    topCard: {
      get: function() {
        return this[0];
      }
    }
  }
);

function merge(oneStack, theOther) {
  var deck = []; 

  while (oneStack.isNotDone && theOther.isNotDone) {

    if (oneStack.topCard < theOther.topCard) {
      deck.push(oneStack.shift()); 
    } else {
      deck.push(theOther.shift());
    }
  }
   
  while(oneStack.isNotDone) {
    deck.push(oneStack.shift()); 
  } 

  while(theOther.isNotDone) {
    deck.push(theOther.shift());
  }

  return deck; 
}

Object.defineProperties(
  Array.prototype, {
    topHalf: {
      get: function() {
        return this.slice(0, this.length/2); 
      }
    },
    bottomHalf: {
      get: function() {
        return this.slice(this.length/2, this.length);
      }
    } 
  }
);

function mergeSort(deck) {
  if (deck.length > 1) {
   return merge(
      mergeSort(deck.topHalf),
      mergeSort(deck.bottomHalf)
    );
  } else {
    return deck; 
  }
}

console.log(mergeSort([0, 1,2, 2, 38,0,-2,11, 2,3]));