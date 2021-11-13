import tensorflow as tf     # pip install tensorflow
import numpy as np

print("Tensorflow ver: ", tf.__version__, "\n")

model = tf.keras.Sequential([tf.keras.layers.Dense(units=1, input_shape=[1])])      # This line initialises one neuron
model.compile(optimizer='sgd', loss='mean_squared_error')             # This line is responsible for improving results

# numpy arrays with training data
xs = np.array([-1,  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16], dtype=float)
ys = np.array([-3, -1, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31], dtype=float)

model.fit(xs, ys, epochs=5000)       # actual training

for quark in xs:
    result = model.predict([int(quark)])
    actual = ys[np.where(xs == quark)]     # works only with non-repeating xs
    print("result: ", result, "actual: ", actual, "error: ", abs(result - actual))
