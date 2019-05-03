import numpy as np
import cv2
import tensorflow as tf
from custom_resnet18 import Model

if __name__ == '__main__':
    image_shape = (1, 224, 224, 3)

    with tf.name_scope('resnet_src'):
	image_model = Model('models/resnet18.npy')
	
    with open("imagenet1000_clsidx_to_labels.txt") as f:
	idx2label = eval(f.read())
	
    data = tf.placeholder(tf.float32, shape = image_shape, name = 'data')
    image_model.build(data)

    image = cv2.imread('/Users/zsc/Downloads/dog.jpg')
    image = cv2.resize(image, image_shape[1:3])
    image = image.reshape(image_shape)
    image = (image/255).astype('float32')

    with tf.Session() as sess:
	sess.run(tf.global_variables_initializer()) # init all variables
	top_k_indices = sess.run(image_model.top_k_indices, feed_dict={data: image})
	for idx in top_k_indices:
	    print(idx2label[idx])
