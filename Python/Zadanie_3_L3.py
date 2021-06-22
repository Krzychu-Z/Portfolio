"""Lab nr3, zadanie 3, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 30.03.2021r."""
import math
from random import uniform
# Monte Carlo sine integration


class MCSineIntegration:
    def __init__(self, bottom, top, amplitude):
        self.bottom = bottom
        self.top = top
        self.all_count = 0
        self.in_count_positive = 0
        self.in_count_negative = 0
        self.amplitude = amplitude

    def perform(self):
        i = 0
        while i < 1000000:
            # uniform returns random float value from given range
            x = uniform(self.bottom, self.top)
            y_guessed = uniform(-1*self.amplitude, self.amplitude)

            if 0 < y_guessed < math.sin(x):
                self.in_count_positive += 1
                self.all_count += 1
            elif math.sin(x) < y_guessed < 0:
                self.in_count_negative += 1
                self.all_count += 1
            else:
                self.all_count += 1

            i += 1

        # Ratio of points under function for positive values minus number of points above function for
        # negative values and all points multiplied by size of rectangle defined by user
        return ((self.in_count_positive - self.in_count_negative)/self.all_count) *\
               (abs(self.top - self.bottom))*2*self.amplitude


product = MCSineIntegration(0, 2, 1)
print("Integrate of this sine function in range (" + str(product.bottom) + ", "
      + str(product.top) + ") = ", product.perform())
