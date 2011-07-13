#Angstrom bootstrap image
require console-base-image.bb

DEPENDS += "task-base-extended \
	   "

#		task-base-extended \
#		task-gstreamer-ti \


IMAGE_INSTALL += " \
		task-sdk-base \
		nano \
		pv \
	    "

export IMAGE_BASENAME = "gw-bb-test-image"
